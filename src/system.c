#include "system.h"
#include "ascii_output.h"
typedef struct
{
  OSCVAR freq;
  void (*actual_output)(const Sample*);
  int (*output_initialize)();
  int (*output_terminate)();
} System;
System this_osc = {1000,ascii_output,ascii_output_initialize,ascii_output_terminate};
void
set_frequency(OSCVAR freq)
{
  this_osc.freq = freq;
}
OSCVAR
get_frequency()
{
  return this_osc.freq;
}
void
set_output (void (*o)(const Sample*))
{
  this_osc.actual_output = o;
}
void (*get_output())(const Sample*)
{
  return this_osc.actual_output;
}
void
set_output_initialize (int (*oi)())
{
  this_osc.output_initialize = oi;
}
int (*get_output_initialize())()
{
  return this_osc.output_initialize;
}
void
set_output_terminate (int (*oi)())
{
  this_osc.output_terminate = oi;
}
int (*get_output_terminate())()
{
  return this_osc.output_terminate;
}
OSCVAR
sample_rate()
{
  return SAMPLE_RATE;
}
