#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <portaudio.h>
#include "osc.h"
#include "system.h"
#include "audio_output.h"
#include "compute.h"

static int
pa_check(int result)
{
  if( result != paNoError )
  {
    printf(  "PortAudio error: %s\n", Pa_GetErrorText( result ) );
    abort();
  }
  return result;
}

static AudioData __data__; /*FIXME brutal hack*/

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
    return Pa_OpenDefaultStream( &stream,
                                0,          /* no input channels */
                                1,          /* mono output */
                                paFloat32,  /* 32 bit floating point output */
                                sample_rate(),
                                paFramesPerBufferUnspecified,        /* frames per buffer, i.e. the number
                                                   of sample frames that PortAudio will
                                                   request from the callback. Many apps
                                                   may want to use
                                                   paFramesPerBufferUnspecified, which
                                                   tells PortAudio to pick the best,
                                                   possibly changing, buffer size.*/
                                pa_audio_output, /* this is your callback function */
                                &__data__ ); /*This is a pointer that will be passed to
                                                   your callback*/
}

void
audio_output()
{
    pa_check(open_audio_stream());
    sleep (10000); /* FIXME : brutal hack */
}

void
audio_output_initialize()
{
  pa_check(Pa_Initialize());
}

int
audio_output_terminate()
{
  return pa_check(Pa_Terminate());
}
