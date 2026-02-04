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
    // Variant 2: Strided access pattern - process channels in reverse strided order (stride of 2, backwards)
    int ch_count = out->ch_count;
    int step = 2;
    int offset = count * out->bps;
    uint8_t **out_ch = out->ch;
    uint8_t **in_ch = in->ch;

    // First pass: odd indices in reverse
    for (ch = (ch_count % 2 == 0) ? ch_count - 1 : ch_count - 2; ch >= 0; ch -= step) {
        out_ch[ch] = in_ch[ch] + offset;
    }
    // Second pass: even indices in reverse
    for (ch = (ch_count % 2 == 1) ? ch_count - 1 : ch_count - 2; ch >= 0; ch -= step) {
        out_ch[ch] = in_ch[ch] + offset;
    }
}
