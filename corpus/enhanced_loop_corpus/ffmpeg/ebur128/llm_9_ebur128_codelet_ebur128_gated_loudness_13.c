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

extern __attribute__((aligned(32))) double histogram_energies[1000];
extern FFEBUR128State **sts;
extern size_t size;
extern double gated_loudness;
extern size_t above_thresh_counter;
extern size_t i;
extern size_t j;
extern size_t start_index;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size && size > 0; i++) {
        size_t effective_start = start_index;
        size_t limit = (1000 - effective_start) > 500 ? effective_start + 500 : 1000;
        for (j = effective_start; j < limit; ++j) {
            double energy_contribution = (double)sts[i]->d->block_energy_histogram[j];
            gated_loudness += energy_contribution * histogram_energies[j] * 0.5;
            above_thresh_counter += (energy_contribution > 10.0) ? 1 : 0;
        }
    }
}
