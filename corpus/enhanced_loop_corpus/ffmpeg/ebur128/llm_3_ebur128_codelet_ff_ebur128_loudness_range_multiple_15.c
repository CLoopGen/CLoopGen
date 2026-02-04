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
    // Strided access with reverse traversal to modify memory access pattern
    for (i = 0; i < size; ++i) {
        if (!sts[i])
            continue;
        unsigned long *hist_data = sts[i]->d->short_term_block_energy_histogram;
        for (j = 999; j != (size_t)-1; j -= 8) {
            // Access in reverse order with stride of 8 (indirectly via decreasing index)
            hist[j] += hist_data[j];
            stl_size += hist_data[j];
            stl_power += hist_data[j] * histogram_energies[j];

            if (j >= 1) {
                hist[j-1] += hist_data[j-1];
                stl_size += hist_data[j-1];
                stl_power += hist_data[j-1] * histogram_energies[j-1];
            }
            if (j >= 2) {
                hist[j-2] += hist_data[j-2];
                stl_size += hist_data[j-2];
                stl_power += hist_data[j-2] * histogram_energies[j-2];
            }
            if (j >= 3) {
                hist[j-3] += hist_data[j-3];
                stl_size += hist_data[j-3];
                stl_power += hist_data[j-3] * histogram_energies[j-3];
            }
            if (j >= 4) {
                hist[j-4] += hist_data[j-4];
                stl_size += hist_data[j-4];
                stl_power += hist_data[j-4] * histogram_energies[j-4];
            }
            if (j >= 5) {
                hist[j-5] += hist_data[j-5];
                stl_size += hist_data[j-5];
                stl_power += hist_data[j-5] * histogram_energies[j-5];
            }
            if (j >= 6) {
                hist[j-6] += hist_data[j-6];
                stl_size += hist_data[j-6];
                stl_power += hist_data[j-6] * histogram_energies[j-6];
            }
            if (j >= 7) {
                hist[j-7] += hist_data[j-7];
                stl_size += hist_data[j-7];
                stl_power += hist_data[j-7] * histogram_energies[j-7];
            }
        }
    }
}
