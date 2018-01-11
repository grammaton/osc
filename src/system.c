#include "system.h"
#include "ascii_output.h"
typedef struct
{
  OSCVAR freq;
  void (*actual_output)(const Sample*);
} System;
System this_osc = {1000,ascii_output};
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
OSCVAR
sample_rate()
{
  return SAMPLE_RATE;
}
