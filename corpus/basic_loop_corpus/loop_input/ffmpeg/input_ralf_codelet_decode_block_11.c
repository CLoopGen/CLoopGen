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

static int16_t dst0_buf[131072];
static int16_t dst1_buf[131072];
static int ch0_buf[131072];
static int ch1_buf[131072];
static RALFContext ctx_instance;

void init_vars() {
    for (int i = 0; i < 131072; i++) {
        ch0_buf[i] = (i * 17) % 32768;
        ch1_buf[i] = (i * 25) % 32768;
    }

    ctx = &ctx_instance;
    ctx->bias[0] = 1024;
    ctx->bias[1] = 2048;

    dst0 = dst0_buf;
    dst1 = dst1_buf;
    ch0 = ch0_buf;
    ch1 = ch1_buf;
    len = 131072;
}