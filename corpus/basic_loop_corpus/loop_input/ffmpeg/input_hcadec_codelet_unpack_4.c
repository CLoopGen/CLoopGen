#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float dequantizer_scaling_table[256];
float quant_step_size[256];

typedef struct ChannelContext {
    float base[128];
    float imdct_in[128] __attribute__((aligned(32)));
    float imdct_out[128] __attribute__((aligned(32)));
    float imdct_prev[128] __attribute__((aligned(32)));
    int8_t scale_factors[128];
    uint8_t scale[128];
    int8_t intensity[8];
    int8_t *hfr_scale;
    unsigned int count;
    int chan_type;
} ChannelContext;

ChannelContext *ch;

void init_vars() {
    for (int i = 0; i < 256; i++) {
        dequantizer_scaling_table[i] = 1.0f + i * 0.1f;
        quant_step_size[i] = 0.5f + i * 0.05f;
    }

    ch = aligned_alloc(32, sizeof(ChannelContext));
    if (!ch) exit(1);

    for (int i = 0; i < 128; i++) {
        ch->scale_factors[i] = rand() % 256;
        ch->scale[i] = rand() % 256;
    }

    ch->count = 128;
    ch->chan_type = 0;
    ch->hfr_scale = NULL;

    for (int i = 0; i < 8; i++) {
        ch->intensity[i] = rand() % 128 - 64;
    }
}