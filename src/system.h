#if !defined(_system_h_)
#	define _system_h_
#define SAMPLE_RATE (44100)
#define OSCVAR double

typedef struct
{
  OSCVAR freq;
  OSCVAR amp;
  OSCVAR phase;
}Osc;

typedef struct
{
  OSCVAR time;
  OSCVAR value;
}Sample;

OSCVAR sample_rate();
OSCVAR get_frequency();
void set_frequency(OSCVAR);
void set_output(void (*)(const Sample*));
void (*get_output()) (const Sample*);
#endif
