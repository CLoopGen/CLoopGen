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



void loop() {
    for (c = 0; c < st->channels; ++c) {
        double max = 0.;
        short **channels_ptr = srcs;
        size_t idx = src_index;
        ptrdiff_t s = stride;
        for (i = 0; i < frames; ++i) {
            size_t access_idx = idx + i * s;
            short v = channels_ptr[c][access_idx];
            if (v < 0) {
                v = -v;
            }
            if (v > max) {
                max = v;
            }
        }
        max /= 32768.0;
        double *peak_ptr = &(st->d->sample_peak[c]);
        if (max > *peak_ptr) {
            *peak_ptr = max;
        }
    }
}
