#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef struct ATRAC9ChannelData {
    int band_ext;
    int q_unit_cnt;
    int band_ext_data[4];
    int32_t scalefactors[31];
    int32_t scalefactors_prev[31];
    int precision_coarse[30];
    int precision_fine[30];
    int precision_mask[30];
    int codebookset[30];
    int32_t q_coeffs_coarse[256];
    int32_t q_coeffs_fine[256];
    float coeffs[256] __attribute__((aligned(32)));
    float prev_win[128] __attribute__((aligned(32)));
} ATRAC9ChannelData;

typedef struct ATRAC9BlockData {
    ATRAC9ChannelData channel[2];
    int band_count;
    int q_unit_cnt;
    int q_unit_cnt_prev;
    int stereo_q_unit;
    int has_band_ext;
    int has_band_ext_data;
    int band_ext_q_unit;
    int grad_mode;
    int grad_boundary;
    int gradient[31];
    int cpe_base_channel;
    int is_signs[30];
    int reuseable;
} ATRAC9BlockData;

ATRAC9BlockData *b;
ATRAC9ChannelData *c;
uint8_t *sf_weights;
int base;

void init_vars() {
    // Allocate and initialize b
    b = (ATRAC9BlockData*)aligned_alloc(32, sizeof(ATRAC9BlockData));
    memset(b, 0, sizeof(ATRAC9BlockData));

    // Set band_ext_q_unit to a safe value within scalefactors array bounds (max 31)
    b->band_ext_q_unit = 30;  // must be <= 30 because scalefactors has size 31

    // Point c to one of the channels, say channel[0]
    c = &b->channel[0];

    // Allocate sf_weights with enough data; since loop runs up to band_ext_q_unit (30),
    // we need at least 30 bytes. But ensure total data size leads to ~0.01 sec runtime.
    // The loop itself is very light; to make it take ~0.01s, we may need larger data.
    // However, the actual work per iteration is minimal. On a modern CPU, millions of iterations
    // take < 0.01s. So we scale up band_ext_q_unit only if allowed by array bounds.
    // But scalefactors is fixed at 31 elements -> limits us.

    // Since the loop bound is b->band_ext_q_unit and scalefactors[i] accessed,
    // we cannot exceed 31. So maximum i is 30.

    // Therefore, we cannot increase data size beyond that without breaking constraints.
    // We accept that this loop will run very fast (< 1ms), but it's bounded by structure.

    // Allocate sf_weights with safe size
    sf_weights = (uint8_t*)malloc(32);
    memset(sf_weights, 1, 32);  // initialize to 1

    // Initialize base
    base = 100;

    // Initialize scalefactors to avoid garbage
    memset(c->scalefactors, 0, sizeof(c->scalefactors));
}