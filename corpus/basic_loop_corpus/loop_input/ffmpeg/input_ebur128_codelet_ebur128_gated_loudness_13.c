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
size_t size = 2000;
double gated_loudness = 0.0;
size_t above_thresh_counter = 0;
size_t i = 0;
size_t j = 0;
size_t start_index = 0;

void init_vars() {
    // Initialize histogram_energies
    for (int idx = 0; idx < 1000; ++idx) {
        histogram_energies[idx] = (double)(idx + 1) / 1000.0;
    }

    // Allocate and initialize block_energy_histogram arrays and internal structures
    sts = (FFEBUR128State**)calloc(size, sizeof(FFEBUR128State*));
    if (!sts) exit(1);

    for (size_t idx = 0; idx < size; ++idx) {
        FFEBUR128State* state = (FFEBUR128State*)malloc(sizeof(FFEBUR128State));
        if (!state) exit(1);

        FFEBUR128StateInternal* internal = (FFEBUR128StateInternal*)malloc(sizeof(FFEBUR128StateInternal));
        if (!internal) exit(1);

        unsigned long* block_hist = (unsigned long*)calloc(1000, sizeof(unsigned long));
        if (!block_hist) exit(1);

        // Simulate meaningful data: set middle portion to non-zero
        for (int h = 0; h < 1000; ++h) {
            block_hist[h] = (h >= 100 && h < 900) ? (h % 7 + 1) : 0;
        }

        internal->block_energy_histogram = block_hist;
        state->d = internal;
        state->mode = 1;
        state->channels = 2;
        state->samplerate = 48000;

        sts[idx] = state;
    }

    // Set start_index to ensure significant loop workload
    start_index = 100;
}