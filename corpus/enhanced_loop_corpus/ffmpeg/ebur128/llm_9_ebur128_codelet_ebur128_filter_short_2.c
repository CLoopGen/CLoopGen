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
    for (c = 0; c < st->channels; ++c) {
        double max = 0.;
        double scale_factor = 1.0 / -((double)(-32767 - 1));
        size_t unroll_factor = 4;
        size_t limit = frames - (frames % unroll_factor);
        for (i = 0; i < limit; i += unroll_factor) {
            short v0 = srcs[c][src_index + (i + 0) * stride];
            short v1 = srcs[c][src_index + (i + 1) * stride];
            short v2 = srcs[c][src_index + (i + 2) * stride];
            short v3 = srcs[c][src_index + (i + 3) * stride];
            double abs_v0 = (v0 > 0) ? v0 : -v0;
            double abs_v1 = (v1 > 0) ? v1 : -v1;
            double abs_v2 = (v2 > 0) ? v2 : -v2;
            double abs_v3 = (v3 > 0) ? v3 : -v3;
            double local_max = abs_v0;
            if (abs_v1 > local_max) local_max = abs_v1;
            if (abs_v2 > local_max) local_max = abs_v2;
            if (abs_v3 > local_max) local_max = abs_v3;
            if (local_max > max) max = local_max;
        }
        for (; i < frames; ++i) {
            short v = srcs[c][src_index + i * stride];
            double abs_v = (v > 0) ? v : -v;
            if (abs_v > max) max = abs_v;
        }
        max *= scale_factor;
        if (max > st->d->sample_peak[c])
            st->d->sample_peak[c] = max;
    }
}
