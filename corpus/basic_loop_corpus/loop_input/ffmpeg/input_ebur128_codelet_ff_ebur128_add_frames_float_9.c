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
float *src;
int i;
float **buf;

void init_vars() {
    st = (FFEBUR128State *)calloc(1, sizeof(FFEBUR128State));
    st->channels = 8;
    st->samplerate = 48000;
    st->mode = 1;

    st->d = (struct FFEBUR128StateInternal *)calloc(1, sizeof(struct FFEBUR128StateInternal));
    st->d->samples_in_100ms = st->samplerate / 10;
    st->d->window = 512;
    st->d->audio_data_frames = 1024;
    st->d->needed_frames = 100;

    st->d->audio_data = (double *)calloc(st->d->audio_data_frames * st->channels, sizeof(double));
    st->d->channel_map = (int *)calloc(st->channels, sizeof(int));
    for (unsigned int ch = 0; ch < st->channels; ch++) {
        st->d->channel_map[ch] = ch;
    }

    st->d->block_energy_histogram = (unsigned long *)calloc(256, sizeof(unsigned long));
    st->d->short_term_block_energy_histogram = (unsigned long *)calloc(32, sizeof(unsigned long));
    st->d->sample_peak = (double *)calloc(st->channels, sizeof(double));
    st->d->data_ptrs = (void **)calloc(st->channels, sizeof(void *));

    for (int k = 0; k < 5; k++) {
        st->d->b[k] = 1.0 / (k + 1);
        st->d->a[k] = 1.0 / (k + 2);
        for (int j = 0; j < 5; j++) {
            st->d->v[k][j] = 0.0;
        }
    }

    src = (float *)calloc(1024 * st->channels, sizeof(float));
    buf = (float **)calloc(st->channels, sizeof(float *));

    for (unsigned int ch = 0; ch < st->channels; ch++) {
        for (size_t j = 0; j < 1024; j++) {
            src[ch * 1024 + j] = (float)(drand48() * 2.0 - 1.0);
        }
    }
}