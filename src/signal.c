#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "system.h"
static void
signal_trap(int sig)
{
  int ret_val = sig;
  printf("\nosc: Caught signal %d\n", sig);
  ret_val = (*get_output_terminate())();
  exit(ret_val);
}
void
init_signals()
{
  int *p;
  int sigs[] = {SIGINT,SIGTERM,SIGHUP,SIGFPE,SIGABRT,SIGALRM,SIGPIPE,0};

  for (p = sigs; *p !=0; ++p)
    signal(*p,signal_trap);
}
