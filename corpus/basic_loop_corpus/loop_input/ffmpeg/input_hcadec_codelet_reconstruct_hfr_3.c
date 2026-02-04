#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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

float scale_conversion_table[64];
ChannelContext *ch;
unsigned int hfr_group_count;
unsigned int bands_per_hfr_group;
unsigned int start_band;
unsigned int total_band_count;

void init_vars() {
    hfr_group_count = 16;
    bands_per_hfr_group = 4;
    start_band = 64;
    total_band_count = 128;

    for (int i = 0; i < 64; i++) {
        scale_conversion_table[i] = 1.0f + (i * 0.01f);
    }

    ch = (ChannelContext*)aligned_alloc(32, sizeof(ChannelContext));
    if (!ch) exit(1);

    for (int i = 0; i < 128; i++) {
        ch->imdct_in[i] = 1.0f + (i * 0.001f);
        ch->scale_factors[i] = (int8_t)((i * 7) % 64) - 32;
    }

    for (int i = 0; i < 8; i++) {
        ch->intensity[i] = (int8_t)(i * 5);
    }

    ch->hfr_scale = (int8_t*)malloc(hfr_group_count * sizeof(int8_t));
    for (unsigned int i = 0; i < hfr_group_count; i++) {
        ch->hfr_scale[i] = (int8_t)((i * 10) % 64) - 30;
    }

    ch->count = 128;
    ch->chan_type = 1;
}