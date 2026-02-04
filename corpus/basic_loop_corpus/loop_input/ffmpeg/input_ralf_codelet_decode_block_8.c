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

int16_t *dst0;
int16_t *dst1;
RALFContext *ctx;
int len;
int *ch0;
int *ch1;
int i;

void init_vars() {
    ctx = (RALFContext*)calloc(1, sizeof(RALFContext));
    if (!ctx) exit(1);

    ctx->bias[0] = 100;
    ctx->bias[1] = 200;

    len = 131072; // ~256KB of output per channel, ensures loop takes ~0.01s

    ch0 = (int*)malloc(len * sizeof(int));
    ch1 = (int*)malloc(len * sizeof(int));
    dst0 = (int16_t*)malloc(len * sizeof(int16_t));
    dst1 = (int16_t*)malloc(len * sizeof(int16_t));

    if (!ch0 || !ch1 || !dst0 || !dst1) exit(1);

    for (int j = 0; j < len; j++) {
        ch0[j] = j % 1000;
        ch1[j] = j % 1500;
    }

    i = 0;
}