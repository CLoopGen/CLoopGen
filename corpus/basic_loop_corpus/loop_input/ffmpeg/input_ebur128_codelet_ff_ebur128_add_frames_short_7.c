#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct FFEBUR128StateInternal {
    double *audio_data;
    size_t audio_data_frames;
    size_t audio_data_index;
    unsigned long needed_frames;
    int *channel_map;
    unsigned long samples_in_100ms;
    double b[5];
    double a[5];
    double v[5][5];
    unsigned long *block_energy_histogram;
    unsigned long *short_term_block_energy_histogram;
    size_t short_term_frame_counter;
    double *sample_peak;
    unsigned long window;
    void **data_ptrs;
};

typedef struct FFEBUR128State {
    int mode;
    unsigned int channels;
    unsigned long samplerate;
    struct FFEBUR128StateInternal *d;
} FFEBUR128State;

FFEBUR128State *st;
short *src;
int i;
short **buf;

void init_vars() {
    st = (FFEBUR128State *)calloc(1, sizeof(FFEBUR128State));
    st->channels = 8;
    st->samplerate = 48000;
    st->d = (struct FFEBUR128StateInternal *)calloc(1, sizeof(struct FFEBUR128StateInternal));

    src = (short *)calloc(1 << 20, sizeof(short));

    buf = (short **)calloc(st->channels, sizeof(short *));
}

void loop();