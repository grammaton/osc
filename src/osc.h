#if !defined(_osc_h_)
#       define _osc_h_
#include "system.h"


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
#endif
