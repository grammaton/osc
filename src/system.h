#if !defined(_system_h_)
#	define _system_h_

#define SAMPLE_RATE (44100)
#define OSCVAR double

OSCVAR sample_rate();
OSCVAR get_frequency();
void set_frequency(OSCVAR);

#endif
