#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double histogram_energies[1000] __attribute__((aligned(32)));

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

FFEBUR128State **sts;
size_t size = 20000;
double *relative_threshold;
size_t i;
size_t j;
int above_thresh_counter;

void init_vars() {
    for (int idx = 0; idx < 1000; ++idx) {
        histogram_energies[idx] = 0.01 + idx * 0.001;
    }

    relative_threshold = (double*)calloc(1, sizeof(double));
    if (!relative_threshold) exit(1);

    sts = (FFEBUR128State**)calloc(size, sizeof(FFEBUR128State*));
    if (!sts) exit(1);

    for (size_t idx = 0; idx < size; ++idx) {
        sts[idx] = (FFEBUR128State*)calloc(1, sizeof(FFEBUR128State));
        if (!sts[idx]) exit(1);
        sts[idx]->d = (struct FFEBUR128StateInternal*)calloc(1, sizeof(struct FFEBUR128StateInternal));
        if (!sts[idx]->d) exit(1);

        sts[idx]->d->block_energy_histogram = (unsigned long*)calloc(1000, sizeof(unsigned long));
        if (!sts[idx]->d->block_energy_histogram) exit(1);

        for (int jdx = 0; jdx < 1000; ++jdx) {
            sts[idx]->d->block_energy_histogram[jdx] = (jdx % 97) + 1;
        }
    }
}