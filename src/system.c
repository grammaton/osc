#include "system.h"
#include "ascii_output.h"
#include "audio_output.h"
typedef void(*output_fun)();
typedef void(*output_initialize_fun)();
typedef int(*output_terminate_fun)();
typedef struct
{
  Osc parameters;
  output_fun actual_output;
  output_initialize_fun output_initialize;
  output_terminate_fun output_terminate;
} System;
System this_osc = {{1000,1.0,0.0},audio_output,audio_output_initialize,audio_output_terminate};

Osc *
get_parameters ()
{
  return &this_osc.parameters;
}
void
set_frequency(OSCVAR freq)
{
  this_osc.parameters.freq = freq;
}
OSCVAR
get_frequency()
{
  return this_osc.parameters.freq;
}
void
set_output (output_fun o)
{
  this_osc.actual_output = o;
}
output_fun get_output()
{
  return this_osc.actual_output;
}
void
set_output_initialize (output_initialize_fun oi)
{
  this_osc.output_initialize = oi;
}
output_initialize_fun get_output_initialize()
{
  return this_osc.output_initialize;
}
void
set_output_terminate (output_terminate_fun oi)
{
  this_osc.output_terminate = oi;
}
output_terminate_fun get_output_terminate()
{
  return this_osc.output_terminate;
}
OSCVAR
sample_rate()
{
  return SAMPLE_RATE;
}
