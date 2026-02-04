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
extern  float *src;
extern int i;
extern  float **buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t total_frames = st->channels * 2;
    for (i = 0; i < total_frames; i += 2) {
        int ch = i / 2;
        if (ch < st->channels) {
            buf[ch] = src + ch;
            if (i + 1 < total_frames && ch + 1 < st->channels) {
                buf[ch + 1] = src + ch + 1;
            }
        }
    }
}
