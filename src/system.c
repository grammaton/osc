#include "system.h"
#include "ascii_output.h"
typedef struct
{
  Osc parameters;
  void (*actual_output)();
  void (*output_initialize)();
  void (*output_terminate)();
} System;
System this_osc = {{1000,1.0,0.0},ascii_output,ascii_output_initialize,ascii_output_terminate};

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
set_output (void (*o)())
{
  this_osc.actual_output = o;
}
void (*get_output())()
{
  return this_osc.actual_output;
}
void
set_output_initialize (void (*oi)())
{
  this_osc.output_initialize = oi;
}
void (*get_output_initialize())()
{
  return this_osc.output_initialize;
}
void
set_output_terminate (void (*oi)())
{
  this_osc.output_terminate = oi;
}
void (*get_output_terminate())()
{
  return this_osc.output_terminate;
}
OSCVAR
sample_rate()
{
  return SAMPLE_RATE;
}
