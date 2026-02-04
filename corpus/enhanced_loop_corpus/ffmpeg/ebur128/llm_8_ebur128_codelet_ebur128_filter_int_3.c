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
extern  int **srcs;
extern size_t src_index;
extern size_t frames;
extern int stride;
extern size_t i;
extern size_t c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled inner loop and additional arithmetic operations
    for (c = 0; c < st->channels; ++c) {
        double max = 0.;
        size_t remainder = frames % 4;
        size_t limit = frames - remainder;

        // Unroll by 4 to increase arithmetic density
        for (i = 0; i < limit; i += 4) {
            int v1 = srcs[c][src_index + i * stride];
            int v2 = srcs[c][(src_index + (i+1) * stride)];
            int v3 = srcs[c][(src_index + (i+2) * stride)];
            int v4 = srcs[c][(src_index + (i+3) * stride)];

            double abs_v1 = (v1 > 0) ? v1 : -v1;
            double abs_v2 = (v2 > 0) ? v2 : -v2;
            double abs_v3 = (v3 > 0) ? v3 : -v3;
            double abs_v4 = (v4 > 0) ? v4 : -v4;

            double temp_max = abs_v1;
            if (abs_v2 > temp_max) temp_max = abs_v2;
            if (abs_v3 > temp_max) temp_max = abs_v3;
            if (abs_v4 > temp_max) temp_max = abs_v4;

            if (temp_max > max) max = temp_max;
        }

        // Handle remaining iterations
        for (; i < frames; ++i) {
            int v = srcs[c][src_index + i * stride];
            double abs_v = (v > 0) ? v : -v;
            if (abs_v > max) max = abs_v;
        }

        max /= -((double)(-2147483647LL - 1));
        if (max > st->d->sample_peak[c])
            st->d->sample_peak[c] = max;
    }
}
