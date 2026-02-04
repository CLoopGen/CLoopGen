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
    for (i = 0; i < size; i += 2) {
        FFEBUR128State *st0 = sts[i];
        FFEBUR128State *st1 = (i + 1 < size) ? sts[i + 1] : NULL;
        unsigned long *hist0 = st0->d->block_energy_histogram;
        unsigned long *hist1 = st1 ? st1->d->block_energy_histogram : NULL;

        for (j = 0; j < 500; ++j) {
            *relative_threshold += hist0[j] * histogram_energies[j];
            above_thresh_counter += hist0[j];

            if (st1) {
                *relative_threshold += hist1[j] * histogram_energies[j];
                above_thresh_counter += hist1[j];
            }
        }
    }
}
