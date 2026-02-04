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

extern ALSBlockData *bd;
extern unsigned int smp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t *samples = bd->raw_samples;
    unsigned int shift = *bd->shift_lsbs;
    for (smp = bd->block_length - 1; smp != (unsigned int)-1; smp--)
        samples[smp] = (unsigned int)samples[smp] << shift;
}
