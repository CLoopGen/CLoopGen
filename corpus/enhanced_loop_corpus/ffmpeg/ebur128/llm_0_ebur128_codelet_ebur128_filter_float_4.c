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
    size_t total_frames = frames * st->channels;
    double max = 0.;
    for (i = 0; i < total_frames; ++i) {
        size_t channel = i / frames;
        size_t frame_index = i % frames;
        float v = srcs[channel][src_index + frame_index * stride];
        if (v > max) {
            max = v;
        } else if (-v > max) {
            max = -1. * v;
        }
        if (frame_index == frames - 1 || channel != (i + 1) / frames) {
            max /= 1.;
            if (max > st->d->sample_peak[channel])
                st->d->sample_peak[channel] = max;
            max = 0.;
        }
    }
}
