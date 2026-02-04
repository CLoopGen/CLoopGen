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
        size_t step = 2;
        for (i = 0; i < frames; i += step) {
            short v1 = srcs[c][src_index + i * stride];
            short v = v1;
            if (i + 1 < frames) {
                short v2 = srcs[c][src_index + (i + 1) * stride];
                v = (v1 > v2) ? v1 : v2;
                short neg_v1 = -v1, neg_v2 = -v2;
                if (neg_v1 > max || neg_v2 > max) {
                    double abs_v = (neg_v1 > neg_v2) ? -v1 : -v2;
                    if (abs_v > max) max = abs_v;
                }
            }
            if (v > max) {
                max = v;
            } else if (-v > max) {
                max = -v;
            }
        }
        max /= -((double)(-32767 - 1));
        if (max > st->d->sample_peak[c])
            st->d->sample_peak[c] = max;
    }
}
