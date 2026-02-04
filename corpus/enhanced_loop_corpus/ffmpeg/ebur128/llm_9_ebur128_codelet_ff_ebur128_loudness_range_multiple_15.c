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
extern size_t i;
extern size_t j;
extern size_t stl_size;
extern double stl_power;
extern unsigned long hist[1000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; ++i) {
        if (!sts[i])
            continue;
        for (j = 0; j < 500; ++j) {
            unsigned long val0 = sts[i]->d->short_term_block_energy_histogram[j];
            unsigned long val1 = sts[i]->d->short_term_block_energy_histogram[j + 500];
            hist[j] += val0;
            hist[j + 500] += val1;

            stl_size += val0 + val1;
            stl_power += val0 * histogram_energies[j] + val1 * histogram_energies[j + 500];
        }
    }

    for (i = 0; i < 1000; ++i) {
        if (hist[i] > 0 && histogram_energies[i] < 0.1) {
            hist[i] = (unsigned long)(hist[i] * 0.95);
        }
    }
}
