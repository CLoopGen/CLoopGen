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
extern double *relative_threshold;
extern size_t i;
extern size_t j;
extern int above_thresh_counter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i++) {
        unsigned long *block_energy_histogram = sts[i]->d->block_energy_histogram;
        size_t unroll_factor = 4;
        size_t limit = 1000 - (1000 % unroll_factor);
        for (j = 0; j < limit; j += unroll_factor) {
            *relative_threshold += block_energy_histogram[j] * histogram_energies[j];
            *relative_threshold += block_energy_histogram[j+1] * histogram_energies[j+1];
            *relative_threshold += block_energy_histogram[j+2] * histogram_energies[j+2];
            *relative_threshold += block_energy_histogram[j+3] * histogram_energies[j+3];
            above_thresh_counter += block_energy_histogram[j] + block_energy_histogram[j+1] +
                                    block_energy_histogram[j+2] + block_energy_histogram[j+3];
        }
        for (; j < 1000; ++j) {
            *relative_threshold += block_energy_histogram[j] * histogram_energies[j];
            above_thresh_counter += block_energy_histogram[j];
        }
    }
}
