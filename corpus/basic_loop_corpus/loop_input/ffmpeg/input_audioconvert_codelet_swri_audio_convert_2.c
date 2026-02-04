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
int ch;
int planes;
unsigned int m;

void init_vars() {
    planes = 64;
    out = (AudioData *)calloc(1, sizeof(AudioData));
    out->ch_count = planes;
    out->bps = 4;
    out->count = 1048576; // ~1MB per channel to ensure sufficient data size
    out->planar = 1;
    out->fmt = AV_SAMPLE_FMT_FLTP;
    out->data = (uint8_t *)calloc(out->count * out->ch_count * out->bps, 1);

    for (int i = 0; i < planes; i++) {
        out->ch[i] = out->data + (i * out->count * out->bps);
    }

    ch = 0;
    m = 0;
}