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
    out = malloc(sizeof(AudioData));
    if (!out) exit(1);

    out->ch_count = 8;
    out->bps = 4;
    out->count = 4096;
    out->planar = 1;
    out->fmt = AV_SAMPLE_FMT_FLTP;
    out->data = malloc(out->ch_count * out->count * out->bps);
    if (!out->data) exit(1);

    for (int c = 0; c < out->ch_count; c++) {
        in_arg[c] = out->data + c * out->count * out->bps;
        out->ch[c] = NULL;
    }

    i = 0;
}