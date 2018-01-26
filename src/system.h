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
Osc *get_parameters();
void set_frequency(OSCVAR);
void set_output(void (*)());
void (*get_output()) ();
void set_output_initialize(void(*)());
void (*get_output_initialize())();
void set_output_terminate(int(*)());
int (*get_output_terminate())();
#endif
