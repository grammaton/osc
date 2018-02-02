#if !defined(_audio_output_h_)
#	define _audio_output_h_

typedef struct
{
  Sample s;
  Osc o;
}AudioData;

void audio_output();
void audio_output_initialize();
int audio_output_terminate();

#endif
