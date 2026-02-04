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
AudioData *in;
int count;
int ch;

static uint8_t *global_data_in;
static uint8_t *global_data_out;
static AudioData in_struct;
static AudioData out_struct;

void init_vars() {
    const int data_size = 64 * 1024 * 1024; // ~64 MB for substantial memory footprint

    global_data_in = (uint8_t*)calloc(data_size, sizeof(uint8_t));
    global_data_out = (uint8_t*)calloc(data_size, sizeof(uint8_t));

    if (!global_data_in || !global_data_out) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    in = &in_struct;
    out = &out_struct;

    in->ch_count = 2;
    in->bps = 4;
    in->count = 1000000;
    in->planar = 1;
    in->fmt = AV_SAMPLE_FMT_FLTP;
    in->data = global_data_in;

    out->ch_count = 2;
    out->bps = 4;
    out->count = 1000000;
    out->planar = 1;
    out->fmt = AV_SAMPLE_FMT_FLTP;
    out->data = global_data_out;

    for (int i = 0; i < in->ch_count; i++) {
        in->ch[i] = global_data_in + i * in->count * in->bps;
    }

    for (int i = 0; i < out->ch_count; i++) {
        out->ch[i] = global_data_out + i * out->count * out->bps;
    }

    count = 1000000;
    ch = 0;
}