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
    if (size == 0) return;
    for (j = 0; j < 1000; ++j) {
        unsigned long temp_hist = 0;
        size_t temp_stl_size = 0;
        double temp_stl_power = 0.0;
        for (i = 0; i < size; ++i) {
            if (!sts[i]) continue;
            temp_hist += sts[i]->d->short_term_block_energy_histogram[j];
            temp_stl_size += sts[i]->d->short_term_block_energy_histogram[j];
            temp_stl_power += sts[i]->d->short_term_block_energy_histogram[j] * histogram_energies[j];
        }
        hist[j] += temp_hist;
        stl_size += temp_stl_size;
        stl_power += temp_stl_power;
    }
}
