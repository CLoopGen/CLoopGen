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
    unsigned int shift = *bd->shift_lsbs;
    for (smp = 0; smp < bd->block_length; smp += 2) {
        bd->raw_samples[smp] = (unsigned int)bd->raw_samples[smp] << shift;
        if (smp + 1 < bd->block_length) {
            bd->raw_samples[smp + 1] = (unsigned int)bd->raw_samples[smp + 1] << shift;
        }
    }
}
