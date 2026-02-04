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
    double temp_peaks[st->channels];
    for (c = 0; c < st->channels; ++c) {
        temp_peaks[c] = st->d->sample_peak[c];
        double max = 0.;
        for (i = 0; i < frames; ++i) {
            short v = srcs[c][src_index + i * stride];
            double abs_v = (v >= 0) ? (double)v : -(double)v;
            if (abs_v > max) {
                max = abs_v;
            }
        }
        max /= 32768.0;
        if (max > temp_peaks[c]) {
            temp_peaks[c] = max;
        }
    }
    for (c = 0; c < st->channels; ++c) {
        st->d->sample_peak[c] = temp_peaks[c];
    }
}
