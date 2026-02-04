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
int **srcs;
size_t src_index;
size_t frames;
int stride;
size_t i;
size_t c;

void init_vars() {
    st = (FFEBUR128State*)calloc(1, sizeof(FFEBUR128State));
    st->mode = 0;
    st->channels = 2;
    st->samplerate = 48000;

    st->d = (struct FFEBUR128StateInternal*)calloc(1, sizeof(struct FFEBUR128StateInternal));
    st->d->sample_peak = (double*)calloc(st->channels, sizeof(double));

    for (int j = 0; j < 5; ++j) {
        st->d->b[j] = 0.0;
        st->d->a[j] = 0.0;
        for (int k = 0; k < 5; ++k) {
            st->d->v[j][k] = 0.0;
        }
    }

    frames = 131072; // ~2.7 seconds at 48kHz, scaled to ensure loop takes ~0.01s with optimizations
    src_index = 0;
    stride = 1;

    srcs = (int**)calloc(st->channels, sizeof(int*));
    for (unsigned int ch = 0; ch < st->channels; ++ch) {
        srcs[ch] = (int*)malloc(frames * stride * sizeof(int));
        for (size_t i = 0; i < frames; ++i) {
            // Generate plausible random-ish audio data in valid int range
            int val = (rand() % 4000000001LL) - 2000000000; // [-2e9, 2e9]
            srcs[ch][src_index + i * stride] = val;
        }
    }
}