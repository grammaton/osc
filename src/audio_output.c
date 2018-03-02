#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <portaudio.h>
#include "osc.h"
#include "system.h"
#include "audio_output.h"
#include "compute.h"

static int
pa_check(int result, const char *caller)
{
  if( result <= 0 && result != paNoError )
  {
    printf(  "%s PortAudio error: %s\n", caller, Pa_GetErrorText( result ) );
    abort();
  }
  return result;
}

static AudioData __data__; /*FIXME brutal hack*/

static void /*FIXME brutal hack*/
pa_device_chooser ()
{
  int numDevices,i;
  pa_check(numDevices = Pa_GetDeviceCount(),"pa_device_chooser");
  for( i=0; i<numDevices; i++ )
  {
    const   PaDeviceInfo *deviceInfo;
    deviceInfo = Pa_GetDeviceInfo( i );
    printf("device %d: %s\n", i, deviceInfo->name );
  }
}

static int
pa_audio_output (const void *input,
                 void *output,
                 unsigned long frameCount,
                 const PaStreamCallbackTimeInfo* timeInfo,
                 PaStreamCallbackFlags statusFlags,
                 void *userData)
{
    /* Cast data passed through stream to our structure. */
    AudioData *data = (AudioData*)userData;
    OSCVAR *out = (OSCVAR*)output;
    unsigned int i;
    (void) input; /* Prevent unused variable warning. */

    for( i=0; i<frameCount; i++ )
    {
        Sample *s = osc_compute(&data->s,&data->o);
        *out++ = s->value;
        increment_time (s);
    }
    return 0;
}

static int
open_audio_stream()
{
    PaStream *stream;
    PaStreamParameters outputParameters = {0};
    PaStreamParameters inputParameters = {0};
    /* FIXME brutal hack */
    outputParameters.channelCount = 1;
    outputParameters.device = 1;
    outputParameters.sampleFormat = paFloat32;
    return Pa_OpenStream( &stream,
                          &inputParameters,
                          &outputParameters,
                          sample_rate(),
                          paFramesPerBufferUnspecified,        /* frames per buffer, i.e. the number
                                                   of sample frames that PortAudio will
                                                   request from the callback. Many apps
                                                   may want to use
                                                   paFramesPerBufferUnspecified, which
                                                   tells PortAudio to pick the best,
                                                   possibly changing, buffer size.*/
                          paNoFlag,
                          pa_audio_output, /* this is your callback function */
                          &__data__ ); /*This is a pointer that will be passed to
                                                   your callback*/
}

void
audio_output()
{
    pa_check(open_audio_stream(),"audio_output");
    sleep (10000); /* FIXME : brutal hack */
}

void
audio_output_initialize()
{
  int err = Pa_Initialize();
  pa_device_chooser();
  pa_check(err,"audio_output_initialize");
}

int
audio_output_terminate()
{
  return pa_check(Pa_Terminate(),"audio_output_terminate");
}
