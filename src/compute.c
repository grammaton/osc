#include <math.h>
#include "system.h"

Sample*
osc_compute(Sample*out, const Osc*parameters)
{
  out->value = parameters->amp*cos(2*M_PI*parameters->freq*out->time+parameters->phase);
  return out;
}

Sample*
increment_time(Sample*out)
{
  out->time += (1/sample_rate());
  return out;
}
