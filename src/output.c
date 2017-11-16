#include <stdio.h>

void
output(const Sample*out)
{
	printf("%8.4f %8.6f\n", out->time, out->value);
}
