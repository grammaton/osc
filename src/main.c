#include "config.h"
#include "osc.h"
#include "system.h"

int
main()
{
	Osc p = {get_frequency(), 1.0, 0.0};
	osc(&p);

	return 0;
}
