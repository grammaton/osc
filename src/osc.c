#include "osc.h"
#include "system.h"

void
osc(const Osc*parameters)
{
  Sample s = { 0.0, 0.0 };
  (*get_output_initialize())();
  (*get_output())();
  (*get_output_terminate())();
}
