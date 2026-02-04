#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

enum AVSampleFormat {
    AV_SAMPLE_FMT_NONE = -1,
    AV_SAMPLE_FMT_U8,
    AV_SAMPLE_FMT_S16,
    AV_SAMPLE_FMT_S32,
    AV_SAMPLE_FMT_FLT,
    AV_SAMPLE_FMT_DBL,
    AV_SAMPLE_FMT_U8P,
    AV_SAMPLE_FMT_S16P,
    AV_SAMPLE_FMT_S32P,
    AV_SAMPLE_FMT_FLTP,
    AV_SAMPLE_FMT_DBLP,
    AV_SAMPLE_FMT_S64,
    AV_SAMPLE_FMT_S64P,
    AV_SAMPLE_FMT_NB
};

typedef struct AudioData {
    uint8_t *ch[64];
    uint8_t *data;
    int ch_count;
    int bps;
    int count;
    int planar;
    enum AVSampleFormat fmt;
} AudioData;

AudioData *out;
uint8_t *in_arg[64];
int i;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // ~64 MB total data to ensure loop overhead dominates
    uint8_t *data_pool = (uint8_t *)calloc(total_data_size, sizeof(uint8_t));
    if (!data_pool) exit(1);

    out = (AudioData *)malloc(sizeof(AudioData));
    if (!out) exit(1);

    out->data = data_pool;
    out->ch_count = 64;  // Maximum number of channels to maximize loop iterations
    out->bps = 4;
    out->count = 16777216; // 16M samples per channel (example, not directly used in loop)
    out->planar = 1;
    out->fmt = AV_SAMPLE_FMT_FLTP;

    // Initialize each channel pointer to a unique offset in the data pool
    size_t chunk_size = total_data_size / out->ch_count;
    for (int c = 0; c < out->ch_count; c++) {
        out->ch[c] = data_pool + c * chunk_size;
    }

    // Zero-initialize in_arg array (will be overwritten in loop)
    for (int c = 0; c < 64; c++) {
        in_arg[c] = NULL;
    }

    i = 0;
}