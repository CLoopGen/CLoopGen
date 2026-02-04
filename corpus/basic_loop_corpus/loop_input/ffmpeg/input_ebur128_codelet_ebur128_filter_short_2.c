#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

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
short **srcs;
size_t src_index;
size_t frames;
int stride;
size_t i;
size_t c;

static double *g_sample_peak = NULL;
static unsigned long g_channels = 0;
static struct FFEBUR128StateInternal *g_internal = NULL;
static short **g_srcs = NULL;

void init_vars() {
    // Set realistic audio parameters
    g_channels = 8; // Multi-channel audio
    src_index = 0;
    stride = 1;
    frames = 65536; // ~1MB of input data per channel (65536 * 8 * sizeof(short) ~ 1MB)
    
    // Allocate and initialize st structure
    st = (FFEBUR128State*)calloc(1, sizeof(FFEBUR128State));
    st->mode = 1;
    st->channels = g_channels;
    st->samplerate = 48000;
    
    g_internal = (struct FFEBUR128StateInternal*)calloc(1, sizeof(struct FFEBUR128StateInternal));
    st->d = g_internal;
    
    // Initialize sample_peak array
    g_sample_peak = (double*)calloc(g_channels, sizeof(double));
    for (unsigned int ch = 0; ch < g_channels; ++ch) {
        g_sample_peak[ch] = 0.0;
    }
    g_internal->sample_peak = g_sample_peak;
    
    // Initialize filter coefficients (not used in loop but part of struct)
    for (int j = 0; j < 5; ++j) {
        g_internal->b[j] = 1.0;
        g_internal->a[j] = 1.0;
        for (int k = 0; k < 5; ++k) {
            g_internal->v[j][k] = 0.0;
        }
    }
    
    // Allocate and initialize source buffers
    g_srcs = (short**)calloc(g_channels, sizeof(short*));
    for (unsigned int ch = 0; ch < g_channels; ++ch) {
        g_srcs[ch] = (short*)malloc(frames * sizeof(short));
        // Initialize with pseudo-random audio data centered around zero
        for (size_t j = 0; j < frames; ++j) {
            // Generate values in range [-32767, 32767]
            g_srcs[ch][j] = (short)((rand() % 65535) - 32767);
        }
    }
    srcs = g_srcs;
}