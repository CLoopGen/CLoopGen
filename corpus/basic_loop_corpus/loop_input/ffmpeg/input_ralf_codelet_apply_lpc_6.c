#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

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

RALFContext *ctx;
int length;
int i;
int j;
int acc;
int *audio;
int bias;
int max_clip;
int min_clip;

static VLC dummy_vlc = { .bits = 0, .table = NULL, .table_size = 0, .table_allocated = 0 };

void init_vars() {
    ctx = (RALFContext*)calloc(1, sizeof(RALFContext));
    if (!ctx) exit(1);

    ctx->version = 1;
    ctx->max_frame_size = 4096;
    ctx->filter_length = 32;
    ctx->filter_bits = 10;
    ctx->bias[0] = 512;
    ctx->bias[1] = 512;
    ctx->num_blocks = 100;
    ctx->sample_offset = 0;
    ctx->has_pkt = 0;

    for (int k = 0; k < 64; k++) {
        ctx->filter[k] = (k < ctx->filter_length) ? (int32_t)(32768 * (1.0 - k / 32.0)) : 0;
    }

    for (int k = 0; k < 2; k++) {
        for (int l = 0; l < 4096; l++) {
            ctx->channel_data[k][l] = 0;
        }
    }

    for (int k = 0; k < 4096; k++) {
        ctx->block_size[k] = 64;
        ctx->block_pts[k] = k * 10;
    }

    memset(ctx->pkt, 0, 16384);

    for (int s = 0; s < 3; s++) {
        ctx->sets[s].filter_params = dummy_vlc;
        ctx->sets[s].bias = dummy_vlc;
        ctx->sets[s].coding_mode = dummy_vlc;
        for (int f = 0; f < 10; f++) {
            for (int g = 0; g < 11; g++) {
                ctx->sets[s].filter_coeffs[f][g] = dummy_vlc;
            }
        }
        for (int h = 0; h < 15; h++) {
            ctx->sets[s].short_codes[h] = dummy_vlc;
        }
        for (int m = 0; m < 125; m++) {
            ctx->sets[s].long_codes[m] = dummy_vlc;
        }
    }

    length = 1 << 20;
    audio = (int*)calloc(length, sizeof(int));
    if (!audio) exit(1);

    for (int idx = 0; idx < length; idx++) {
        audio[idx] = (idx % 256) - 128;
    }

    bias = 1024;
    max_clip = 32767;
    min_clip = -32768;

    i = 0;
    j = 0;
    acc = 0;
}