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

FFEBUR128State *st;
float **srcs;
size_t src_index;
size_t frames;
int stride;
size_t i;
size_t c;

void init_vars() {
    const unsigned int num_channels = 8;
    const size_t total_frames = 4000000; // ~1.3 MB of float data per channel
    const size_t target_time_ns_per_iter = 10000000; // Aim for ~10ms
    const size_t estimated_ops_per_frame = 10;
    const size_t ops_per_sec = 1000000000 / target_time_ns_per_iter;
    const size_t desired_frames = ops_per_sec / (num_channels * estimated_ops_per_frame);

    frames = (desired_frames > total_frames) ? total_frames : desired_frames;
    src_index = 0;
    stride = 1;

    st = malloc(sizeof(FFEBUR128State));
    st->mode = 1;
    st->channels = num_channels;
    st->samplerate = 48000;
    st->d = malloc(sizeof(struct FFEBUR128StateInternal));

    st->d->sample_peak = calloc(num_channels, sizeof(double));
    for (unsigned int ch = 0; ch < num_channels; ++ch) {
        st->d->sample_peak[ch] = 0.0;
    }

    srcs = malloc(num_channels * sizeof(float*));
    for (unsigned int ch = 0; ch < num_channels; ++ch) {
        srcs[ch] = malloc(total_frames * sizeof(float));
        for (size_t j = 0; j < total_frames; ++j) {
            srcs[ch][j] = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
        }
    }
}