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
extern  short **srcs;
extern size_t src_index;
extern size_t frames;
extern int stride;
extern size_t i;
extern size_t c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (frames == 0) return;
    for (c = 0; c < st->channels; ++c) {
        double max = 0.;
        size_t unrolled_i = 0;
        size_t remainder = frames % 4;
        for (i = 0; i < remainder; ++i) {
            short v = srcs[c][src_index + i * stride];
            if (v > max) {
                max = v;
            } else if (-v > max) {
                max = -1. * v;
            }
        }
        for (; unrolled_i < frames - remainder; unrolled_i += 4) {
            short v0 = srcs[c][src_index + (unrolled_i + 0) * stride];
            short v1 = srcs[c][src_index + (unrolled_i + 1) * stride];
            short v2 = srcs[c][src_index + (unrolled_i + 2) * stride];
            short v3 = srcs[c][src_index + (unrolled_i + 3) * stride];

            if (v0 > max) max = v0; else if (-v0 > max) max = -v0;
            if (v1 > max) max = v1; else if (-v1 > max) max = -v1;
            if (v2 > max) max = v2; else if (-v2 > max) max = -v2;
            if (v3 > max) max = v3; else if (-v3 > max) max = -v3;
        }
        max /= -((double)(-32767 - 1));
        if (max > st->d->sample_peak[c])
            st->d->sample_peak[c] = max;
    }
}
