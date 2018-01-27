#include <stdio.h>
#include "osc.h"
#include "system.h"

void
output(const Sample*out)
{
	void (*o) (const Sample*) = get_output();
	(*o) (out);
}
