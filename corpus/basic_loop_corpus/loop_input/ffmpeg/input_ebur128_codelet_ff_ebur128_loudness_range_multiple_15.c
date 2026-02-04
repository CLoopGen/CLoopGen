#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double histogram_energies[1000] __attribute__((aligned(32)));

typedef struct FFEBUR128StateInternal {
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
} FFEBUR128StateInternal;

typedef struct FFEBUR128State {
    int mode;
    unsigned int channels;
    unsigned long samplerate;
    struct FFEBUR128StateInternal *d;
} FFEBUR128State;

FFEBUR128State **sts;
size_t size = 256; 
size_t i;
size_t j;
size_t stl_size;
double stl_power;
unsigned long hist[1000];

void init_vars() {
    for (int k = 0; k < 1000; ++k) {
        histogram_energies[k] = 0.1 * k;
        hist[k] = 0;
    }

    sts = calloc(size, sizeof(FFEBUR128State*));
    if (!sts) exit(1);

    for (i = 0; i < size; ++i) {
        sts[i] = malloc(sizeof(FFEBUR128State));
        if (!sts[i]) exit(1);

        sts[i]->mode = 1;
        sts[i]->channels = 2;
        sts[i]->samplerate = 48000;

        sts[i]->d = malloc(sizeof(FFEBUR128StateInternal));
        if (!sts[i]->d) exit(1);

        sts[i]->d->short_term_block_energy_histogram = malloc(1000 * sizeof(unsigned long));
        if (!sts[i]->d->short_term_block_energy_histogram) exit(1);

        for (j = 0; j < 1000; ++j) {
            sts[i]->d->short_term_block_energy_histogram[j] = (i + 1) * (j % 100 + 1);
        }

        sts[i]->d->audio_data = NULL;
        sts[i]->d->audio_data_frames = 0;
        sts[i]->d->audio_data_index = 0;
        sts[i]->d->needed_frames = 0;
        sts[i]->d->channel_map = NULL;
        sts[i]->d->samples_in_100ms = 4800;
        for (int k = 0; k < 5; ++k) {
            sts[i]->d->b[k] = 1.0;
            sts[i]->d->a[k] = 1.0;
            for (int l = 0; l < 5; ++l) {
                sts[i]->d->v[k][l] = 0.0;
            }
        }
        sts[i]->d->block_energy_histogram = NULL;
        sts[i]->d->short_term_frame_counter = 0;
        sts[i]->d->sample_peak = NULL;
        sts[i]->d->window = 1024;
        sts[i]->d->data_ptrs = NULL;
    }

    stl_size = 0;
    stl_power = 0.0;
}