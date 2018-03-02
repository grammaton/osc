#include "config.h"
#include "osc.h"
#include "system.h"
#include "options.h"

void init_signals();

int
main(int argc, char*argv[])
{
	Osc p = {get_frequency(), 1.0, 0.0};
	init_signals();
	manage_options(argc,argv);
	p.freq = get_frequency();
	osc(&p);

	return 0;
}
