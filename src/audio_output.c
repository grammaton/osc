#include <stdlib.h>
#include <stdio.h>
#include <portaudio.h>
#include "osc.h"

void
audio_output()
{

}

static void
common_initialization_termination(int result)
{
  if( result != paNoError )
  {
    printf(  "PortAudio error: %s\n", Pa_GetErrorText( result ) );
    abort();
  }
}

void
audio_output_initialize()
{
  common_initialization_termination(Pa_Initialize());
}

void
audio_output_terminate()
{
  common_initialization_termination(Pa_Terminate());
}
