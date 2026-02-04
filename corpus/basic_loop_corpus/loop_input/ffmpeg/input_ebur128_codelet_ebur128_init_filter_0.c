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
int i;
int j;

static struct FFEBUR128StateInternal internal_state;
static double *alloc_audio_data = NULL;
static int *alloc_channel_map = NULL;
static unsigned long *alloc_block_energy_histogram = NULL;
static unsigned long *alloc_short_term_block_energy_histogram = NULL;
static double *alloc_sample_peak = NULL;
static void **alloc_data_ptrs = NULL;

void init_vars() {
    // Allocate large buffers to ensure loop takes ~0.01 seconds
    // The actual loop is very small (5x5), so we focus on realistic data sizes for the structure

    alloc_audio_data = (double*)calloc(131072, sizeof(double));
    alloc_channel_map = (int*)calloc(32, sizeof(int));
    alloc_block_energy_histogram = (unsigned long*)calloc(256, sizeof(unsigned long));
    alloc_short_term_block_energy_histogram = (unsigned long*)calloc(64, sizeof(unsigned long));
    alloc_sample_peak = (double*)calloc(32, sizeof(double));
    alloc_data_ptrs = (void**)calloc(16, sizeof(void*));

    // Initialize channel map
    for (int ch = 0; ch < 32; ++ch) {
        alloc_channel_map[ch] = ch;
    }

    // Initialize data pointers
    for (int p = 0; p < 16; ++p) {
        alloc_data_ptrs[p] = calloc(1024, sizeof(char));
    }

    // Initialize internal state
    internal_state.audio_data = alloc_audio_data;
    internal_state.audio_data_frames = 131072;
    internal_state.audio_data_index = 0;
    internal_state.needed_frames = 1024;
    internal_state.channel_map = alloc_channel_map;
    internal_state.samples_in_100ms = 4800;
    for (int k = 0; k < 5; ++k) {
        internal_state.b[k] = 0.0;
        internal_state.a[k] = 0.0;
        for (int l = 0; l < 5; ++l) {
            internal_state.v[k][l] = 0.0;
        }
    }
    internal_state.block_energy_histogram = alloc_block_energy_histogram;
    internal_state.short_term_block_energy_histogram = alloc_short_term_block_energy_histogram;
    internal_state.short_term_frame_counter = 0;
    internal_state.sample_peak = alloc_sample_peak;
    internal_state.window = 1024;
    internal_state.data_ptrs = alloc_data_ptrs;

    // Initialize main state
    st = (FFEBUR128State*)malloc(sizeof(FFEBUR128State));
    st->mode = 1;
    st->channels = 2;
    st->samplerate = 48000;
    st->d = &internal_state;

    i = 0;
    j = 0;
}