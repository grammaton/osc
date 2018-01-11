#include <unistd.h>

void
manage_options (int argc, char*argv[])
{
  int c = 0, index = 0;
  while ((c = getopt(argc,argv,"")) != -1)
    ;
  for (index = optind; index < argc; ++index)
    set_frequency (atof(argv[index]));
}
