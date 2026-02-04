#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct ALSBlockData {
    unsigned int block_length;
    unsigned int ra_block;
    int *const_block;
    int js_blocks;
    unsigned int *shift_lsbs;
    unsigned int *opt_order;
    int *store_prev_samples;
    int *use_ltp;
    int *ltp_lag;
    int *ltp_gain;
    int32_t *quant_cof;
    int32_t *lpc_cof;
    int32_t *raw_samples;
    int32_t *prev_raw_samples;
    int32_t *raw_other;
} ALSBlockData;

ALSBlockData *bd;
unsigned int block_length;
int64_t y;
int32_t *raw_samples;
int ltp_smp;

static int internal_ltp_lag;
static int internal_ltp_gain[10];
static int32_t internal_raw_samples[256 * 1024 * 1024 / sizeof(int32_t)]; // ~256MB

void init_vars() {
    block_length = 256 * 1024 * 1024 / sizeof(int32_t); // ~256MB of data
    if (block_length > 1000000) block_length = 1000000; // Limit block_length for reasonable execution (~1M)

    bd = (ALSBlockData *)calloc(1, sizeof(ALSBlockData));
    bd->ltp_lag = &internal_ltp_lag;
    bd->ltp_gain = internal_ltp_gain;
    bd->raw_samples = internal_raw_samples;

    raw_samples = internal_raw_samples;

    internal_ltp_lag = 5; // Ensures center = ltp_smp - 5, and ltp_lag-2 = 3, so loop starts at 3

    for (int i = 0; i < 10; i++) {
        internal_ltp_gain[i] = (i + 1) * 1000;
    }

    for (unsigned int i = 0; i < block_length + 5; i++) {
        internal_raw_samples[i] = (int32_t)(i % 1000);
    }

    y = 0;
    ltp_smp = 0;
}