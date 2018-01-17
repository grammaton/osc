#include <stdio.h>
#include "osc.h"
#include "compute.h"

void
ascii_output_initialize()
{}

void
ascii_output()
{
	Sample s = {0.0, 1.0};
	Osc *parameters = get_parameters();
	while (1)
  {
    Sample *o = &s;
    o = osc_compute(o,parameters);
    printf("%8.4f %8.6f\n", o->time, o->value);
		o = increment_time(o);
	}
}

void
ascii_output_terminate()
{}
