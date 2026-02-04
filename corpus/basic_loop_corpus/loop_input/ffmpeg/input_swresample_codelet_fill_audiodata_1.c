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

static uint8_t *global_data_buffer;
static AudioData global_out;

void init_vars() {
    const int total_data_size = 64 * 1024 * 1024; // 64 MB for substantial memory access (~0.01 sec on modern CPU)
    global_data_buffer = (uint8_t *)calloc(total_data_size, sizeof(uint8_t));
    if (!global_data_buffer) exit(1);

    in_arg[0] = global_data_buffer;

    global_out.ch_count = 8;
    global_out.bps = 4096;
    global_out.count = 16384;
    global_out.planar = 1;
    global_out.fmt = AV_SAMPLE_FMT_FLTP;
    global_out.data = global_data_buffer;

    for (int j = 0; j < 64; j++) {
        global_out.ch[j] = NULL;
    }

    out = &global_out;
}