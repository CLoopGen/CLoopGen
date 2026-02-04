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

static uint8_t *global_data_in = NULL;
static uint8_t *global_data_out = NULL;
static AudioData in_struct;
static AudioData out_struct;

void init_vars() {
    const int target_size_mb = 64;
    const int data_size = target_size_mb * 1024 * 1024;

    global_data_in = (uint8_t*)calloc(data_size, 1);
    global_data_out = (uint8_t*)calloc(data_size, 1);

    if (!global_data_in || !global_data_out) {
        exit(1);
    }

    in_struct.ch_count = 2;
    in_struct.bps = 4;
    in_struct.count = data_size / (in_struct.ch_count * in_struct.bps);
    in_struct.planar = 1;
    in_struct.fmt = AV_SAMPLE_FMT_FLTP;
    in_struct.data = global_data_in;
    for (int i = 0; i < in_struct.ch_count; i++) {
        in_struct.ch[i] = global_data_in + i * in_struct.bps;
    }

    out_struct.ch_count = 2;
    out_struct.bps = 4;
    out_struct.count = in_struct.count;
    out_struct.planar = 1;
    out_struct.fmt = AV_SAMPLE_FMT_FLTP;
    out_struct.data = global_data_out;
    for (int i = 0; i < out_struct.ch_count; i++) {
        out_struct.ch[i] = global_data_out + i * out_struct.bps;
    }

    in = &in_struct;
    out = &out_struct;
    count = 1000;
    ch = 0;
}