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

extern int16_t *dst0;
extern int16_t *dst1;
extern RALFContext *ctx;
extern int len;
extern int *ch0;
extern int *ch1;
extern int i;
extern unsigned int t;
extern unsigned int t2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int unroll_factor = 4;
    int limit = (len / unroll_factor) * unroll_factor;
    for (i = 0; i < limit; i += unroll_factor) {
        unsigned int t_vals[unroll_factor];
        unsigned int t2_vals[unroll_factor];

        t_vals[0] = ch1[i] + ctx->bias[1];
        t2_vals[0] = ((ch0[i] + ctx->bias[0]) * 2) | (t_vals[0] & 1);
        dst0[i] = (int)(t2_vals[0] + t_vals[0]) / 2;
        dst1[i] = (int)(t2_vals[0] - t_vals[0]) / 2;

        t_vals[1] = ch1[i+1] + ctx->bias[1];
        t2_vals[1] = ((ch0[i+1] + ctx->bias[0]) * 2) | (t_vals[1] & 1);
        dst0[i+1] = (int)(t2_vals[1] + t_vals[1]) / 2;
        dst1[i+1] = (int)(t2_vals[1] - t_vals[1]) / 2;

        t_vals[2] = ch1[i+2] + ctx->bias[1];
        t2_vals[2] = ((ch0[i+2] + ctx->bias[0]) * 2) | (t_vals[2] & 1);
        dst0[i+2] = (int)(t2_vals[2] + t_vals[2]) / 2;
        dst1[i+2] = (int)(t2_vals[2] - t_vals[2]) / 2;

        t_vals[3] = ch1[i+3] + ctx->bias[1];
        t2_vals[3] = ((ch0[i+3] + ctx->bias[0]) * 2) | (t_vals[3] & 1);
        dst0[i+3] = (int)(t2_vals[3] + t_vals[3]) / 2;
        dst1[i+3] = (int)(t2_vals[3] - t_vals[3]) / 2;
    }
    for (; i < len; i++) {
        t = ch1[i] + ctx->bias[1];
        t2 = ((ch0[i] + ctx->bias[0]) * 2) | (t & 1);
        dst0[i] = (int)(t2 + t) / 2;
        dst1[i] = (int)(t2 - t) / 2;
    }
}
