#include "config.h"
#include "osc.h"
#include "system.h"
#include "options.h"

int
main(int argc, char*argv[])
{
	Osc p = {get_frequency(), 1.0, 0.0};
	manage_options(argc,argv);
	p.freq = get_frequency();
	osc(&p);

	return 0;
}
