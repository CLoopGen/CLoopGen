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
int *src;
int i;
int **buf;

void init_vars() {
    st = (FFEBUR128State *)calloc(1, sizeof(FFEBUR128State));
    st->channels = 8;
    st->samplerate = 48000;
    st->d = (struct FFEBUR128StateInternal *)calloc(1, sizeof(struct FFEBUR128StateInternal));

    for (int j = 0; j < 5; j++) {
        st->d->b[j] = 1.0;
        st->d->a[j] = 1.0;
        for (int k = 0; k < 5; k++) {
            st->d->v[j][k] = 0.0;
        }
    }

    st->d->samples_in_100ms = st->samplerate / 10;
    st->d->window = 512;
    st->d->short_term_frame_counter = 0;

    size_t data_size = 16777216;
    src = (int *)calloc(data_size, sizeof(int));
    buf = (int **)calloc(st->channels, sizeof(int *));

    for (unsigned int c = 0; c < st->channels; c++) {
        st->d->data_ptrs = realloc(st->d->data_ptrs, (c + 1) * sizeof(void *));
        st->d->data_ptrs[c] = src + c * (data_size / st->channels);
    }
}