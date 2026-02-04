#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct VLC {
    int bits;
    int16_t (*table)[2];
    int table_size;
    int table_allocated;
} VLC;

typedef struct VLCSet {
    VLC filter_params;
    VLC bias;
    VLC coding_mode;
    VLC filter_coeffs[10][11];
    VLC short_codes[15];
    VLC long_codes[125];
} VLCSet;

typedef struct RALFContext {
    int version;
    int max_frame_size;
    VLCSet sets[3];
    int32_t channel_data[2][4096];
    int filter_params;
    int filter_length;
    int filter_bits;
    int32_t filter[64];
    unsigned int bias[2];
    int num_blocks;
    int sample_offset;
    int block_size[4096];
    int block_pts[4096];
    uint8_t pkt[16384];
    int has_pkt;
} RALFContext;

extern RALFContext *ctx;
extern int length;
extern int i;
extern int j;
extern int acc;
extern int *audio;
extern int bias;
extern int max_clip;
extern int min_clip;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int unroll_factor = 4;
int limit = length - (length % unroll_factor);
for (i = 1; i < limit; i += unroll_factor) {
    for (int u = 0; u < unroll_factor; u++) {
        int idx = i + u;
        if (idx >= length) break;
        int flen = (ctx->filter_length > idx) ? idx : ctx->filter_length;
        acc = 0;
        for (j = 0; j < flen; j++) {
            acc += (unsigned int)ctx->filter[j] * audio[idx - j - 1];
        }
        acc = (acc < 0) ? ((acc + bias - 1) >> ctx->filter_bits) : ((acc + bias) >> ctx->filter_bits);
        acc = (acc < min_clip) ? min_clip : (acc > max_clip ? max_clip : acc);
        audio[idx] += acc;
    }
}
for (; i < length; i++) {
    int flen = (ctx->filter_length > i) ? i : ctx->filter_length;
    acc = 0;
    for (j = 0; j < flen; j++)
        acc += (unsigned int)ctx->filter[j] * audio[i - j - 1];
    acc = (acc < 0) ? ((acc + bias - 1) >> ctx->filter_bits) : ((acc + bias) >> ctx->filter_bits);
    acc = (acc < min_clip) ? min_clip : (acc > max_clip ? max_clip : acc);
    audio[i] += acc;
}
}
