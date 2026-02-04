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
        short local_max = 0;
        for (i = 0; i < frames; ++i) {
            short v = srcs[c][src_index + i * stride];
            if (v > local_max) {
                local_max = v;
            }
            if (-v > local_max) {
                local_max = -v;
            }
        }
        max = (double)local_max;
        max /= -((double)(-32767 - 1));
        if (max > st->d->sample_peak[c])
            st->d->sample_peak[c] = max;
    }
}
