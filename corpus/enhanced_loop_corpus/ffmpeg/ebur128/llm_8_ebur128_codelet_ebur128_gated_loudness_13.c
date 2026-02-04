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
    for (i = 0; i < size; i++) {
        double local_loudness = 0.0;
        size_t local_counter = 0;
        for (j = start_index; j < 1000; j += 4) {
            local_loudness += sts[i]->d->block_energy_histogram[j] * histogram_energies[j];
            local_counter += sts[i]->d->block_energy_histogram[j];
            if (j + 1 < 1000) {
                local_loudness += sts[i]->d->block_energy_histogram[j + 1] * histogram_energies[j + 1];
                local_counter += sts[i]->d->block_energy_histogram[j + 1];
            }
            if (j + 2 < 1000) {
                local_loudness += sts[i]->d->block_energy_histogram[j + 2] * histogram_energies[j + 2];
                local_counter += sts[i]->d->block_energy_histogram[j + 2];
            }
            if (j + 3 < 1000) {
                local_loudness += sts[i]->d->block_energy_histogram[j + 3] * histogram_energies[j + 3];
                local_counter += sts[i]->d->block_energy_histogram[j + 3];
            }
        }
        gated_loudness += local_loudness;
        above_thresh_counter += local_counter;
    }
}
