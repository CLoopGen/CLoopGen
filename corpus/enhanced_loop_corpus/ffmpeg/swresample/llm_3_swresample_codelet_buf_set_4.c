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

extern AudioData *out;
extern AudioData *in;
extern int count;
extern int ch;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed indexing but consecutive output assignment
    int i;
    uint8_t *base = in->ch[0] + count * out->ch_count * out->bps;
    int step = out->bps;
    for (i = 0; i < out->ch_count; i++) {
        out->ch[out->ch_count - 1 - i] = base + i * step;
    }
}
