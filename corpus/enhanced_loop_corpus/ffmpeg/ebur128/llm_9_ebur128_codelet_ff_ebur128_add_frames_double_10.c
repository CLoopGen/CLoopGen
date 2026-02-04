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
extern  double *src;
extern int i;
extern  double **buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = st->channels > 4 ? 2 : 1;
    size_t limit = st->channels + (st->channels % step);
    for (i = 0; i < limit; i += step) {
        if (i < st->channels) {
            buf[i] = src + i;
        }
        if (i + 1 < st->channels) {
            buf[i + 1] = src + (i + 1);
        }
    }
}
