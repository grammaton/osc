#include <math.h>
#include "osc.h"
#include "system.h"
#include "output.h"


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

void 
osc(const Osc*parameters)
{
  Sample s = { 0.0, 0.0 };
  while (1)
  {
    Sample *o = osc_compute(&s,parameters);
    output(o);
		o = increment_time(o);
	}
}
