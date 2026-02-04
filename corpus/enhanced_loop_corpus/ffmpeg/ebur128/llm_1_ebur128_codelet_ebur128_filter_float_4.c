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

extern FFEBUR128State *st;
extern  float **srcs;
extern size_t src_index;
extern size_t frames;
extern int stride;
extern size_t i;
extern size_t c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_max[64]; // Assuming maximum of 64 channels
    for (c = 0; c < st->channels; ++c) {
        local_max[c] = 0.;
        for (size_t chunk = 0; chunk < frames; chunk += 8) {
            double temp_max = 0.;
            for (size_t j = 0; j < 8 && (chunk + j) < frames; ++j) {
                size_t idx = src_index + (chunk + j) * stride;
                float v = srcs[c][idx];
                double abs_v = (v > 0) ? v : -v;
                if (abs_v > temp_max) {
                    temp_max = abs_v;
                }
            }
            if (temp_max > local_max[c]) {
                local_max[c] = temp_max;
            }
        }
        local_max[c] /= 1.;
        if (local_max[c] > st->d->sample_peak[c])
            st->d->sample_peak[c] = local_max[c];
    }
}
