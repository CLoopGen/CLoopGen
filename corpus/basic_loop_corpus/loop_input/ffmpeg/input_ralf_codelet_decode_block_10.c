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
unsigned int t;
unsigned int t2;

void init_vars() {
    len = 65536; // ~65k elements for ~0.01 sec runtime

    dst0 = (int16_t*)calloc(len, sizeof(int16_t));
    dst1 = (int16_t*)calloc(len, sizeof(int16_t));
    ch0 = (int*)calloc(len, sizeof(int));
    ch1 = (int*)calloc(len, sizeof(int));

    ctx = (RALFContext*)calloc(1, sizeof(RALFContext));

    ctx->bias[0] = 1000;
    ctx->bias[1] = 2000;

    for (int i = 0; i < len; i++) {
        ch0[i] = i % 32768;
        ch1[i] = (i + 100) % 32768;
    }
}