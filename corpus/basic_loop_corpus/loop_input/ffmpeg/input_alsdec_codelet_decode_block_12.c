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

static ALSBlockData bd_instance;
ALSBlockData *bd = &bd_instance;

static unsigned int global_shift_lsbs;
static int32_t *raw_samples_array;

unsigned int smp;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB of int32_t data
    bd->block_length = (unsigned int)(data_size / sizeof(int32_t));
    bd->ra_block = 0;
    bd->const_block = NULL;
    bd->js_blocks = 0;
    bd->shift_lsbs = &global_shift_lsbs;
    bd->opt_order = NULL;
    bd->store_prev_samples = NULL;
    bd->use_ltp = NULL;
    bd->ltp_lag = NULL;
    bd->ltp_gain = NULL;
    bd->quant_cof = NULL;
    bd->lpc_cof = NULL;

    raw_samples_array = (int32_t*)calloc(bd->block_length, sizeof(int32_t));
    if (!raw_samples_array) exit(1);

    for (unsigned int i = 0; i < bd->block_length; ++i) {
        raw_samples_array[i] = (int32_t)(i & 0xFFFFF);
    }

    bd->raw_samples = raw_samples_array;
    bd->prev_raw_samples = NULL;
    bd->raw_other = NULL;

    global_shift_lsbs = 1;
}