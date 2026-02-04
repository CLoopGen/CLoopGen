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
double *src;
int i;
double **buf;

void init_vars() {
    const unsigned int num_channels = 8;
    const size_t data_size = 32 * 1024 * 1024 / sizeof(double); // ~256MB total for all channels

    st = (FFEBUR128State*)calloc(1, sizeof(FFEBUR128State));
    st->channels = num_channels;
    st->samplerate = 48000;
    st->mode = 1;

    st->d = (struct FFEBUR128StateInternal*)calloc(1, sizeof(struct FFEBUR128StateInternal));
    st->d->audio_data_frames = data_size;
    st->d->samples_in_100ms = st->samplerate / 10;
    st->d->window = 512;

    src = (double*)calloc(data_size * num_channels, sizeof(double));
    buf = (double**)calloc(num_channels, sizeof(double*));

    st->d->channel_map = (int*)calloc(num_channels, sizeof(int));
    for (unsigned int c = 0; c < num_channels; c++) {
        st->d->channel_map[c] = c;
    }

    st->d->block_energy_histogram = (unsigned long*)calloc(256, sizeof(unsigned long));
    st->d->short_term_block_energy_histogram = (unsigned long*)calloc(32, sizeof(unsigned long));
    st->d->sample_peak = (double*)calloc(num_channels, sizeof(double));
    st->d->data_ptrs = (void**)calloc(10, sizeof(void*));

    for (int j = 0; j < 5; j++) {
        st->d->b[j] = 1.0 / (j + 1);
        st->d->a[j] = 1.0 / (j + 2);
        for (int k = 0; k < 5; k++) {
            st->d->v[j][k] = 0.0;
        }
    }
}