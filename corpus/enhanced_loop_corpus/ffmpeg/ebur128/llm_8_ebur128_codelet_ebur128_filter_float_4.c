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
    for (c = 0; c < st->channels; ++c) {
        double max = 0.;
        size_t unrolled_frames = frames - (frames % 4);
        for (i = 0; i < unrolled_frames; i += 4) {
            float v1 = srcs[c][src_index + i * stride];
            float v2 = srcs[c][src_index + (i + 1) * stride];
            float v3 = srcs[c][src_index + (i + 2) * stride];
            float v4 = srcs[c][src_index + (i + 3) * stride];

            double abs_v1 = v1 > 0. ? v1 : -v1;
            double abs_v2 = v2 > 0. ? v2 : -v2;
            double abs_v3 = v3 > 0. ? v3 : -v3;
            double abs_v4 = v4 > 0. ? v4 : -v4;

            double temp_max1 = abs_v1 > abs_v2 ? abs_v1 : abs_v2;
            double temp_max2 = abs_v3 > abs_v4 ? abs_v3 : abs_v4;
            double pair_max = temp_max1 > temp_max2 ? temp_max1 : temp_max2;

            if (pair_max > max) max = pair_max;
        }
        for (; i < frames; ++i) {
            float v = srcs[c][src_index + i * stride];
            double abs_v = v > 0. ? v : -v;
            if (abs_v > max) max = abs_v;
        }
        max /= 1.;
        if (max > st->d->sample_peak[c])
            st->d->sample_peak[c] = max;
    }
}
