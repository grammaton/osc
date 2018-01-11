lib_LTLIBRARIES = libosc.la
bin_PROGRAMS = osc
libosc_la_SOURCES = osc.c system.c output.c options.c ascii_output.c audio_output.c
osc_SOURCES = main.c
osc_LDADD = $(INTI_LIBS) -losc -lm
#AM_LDFLAGS = -lm
