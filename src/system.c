#include "system.h"
typedef struct
{
  OSCVAR freq;
} System;
System this_osc = {1000};
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
OSCVAR
sample_rate()
{
  return SAMPLE_RATE;
}
