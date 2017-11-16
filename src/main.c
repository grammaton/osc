#include "config.h"
#include "osc.h"

int
main()
{
	Osc p = {23.0, 1.0, 0.0};
	osc(&p);
	
	return 0;
}
