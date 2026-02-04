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
    if (st->channels == 0 || frames == 0) return;
    for (size_t i = 0; i < frames; ++i) {
        for (size_t c = 0; c < st->channels; ++c) {
            int v = srcs[c][src_index + i * stride];
            double abs_v = (v > 0) ? v : -v;
            double normalized_abs_v = abs_v / -((double)(-2147483647 - 1));
            if (normalized_abs_v > st->d->sample_peak[c]) {
                st->d->sample_peak[c] = normalized_abs_v;
            }
        }
    }
}
