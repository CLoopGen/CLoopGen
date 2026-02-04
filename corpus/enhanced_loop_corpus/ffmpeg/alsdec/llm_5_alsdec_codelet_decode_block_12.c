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
    unsigned int shift_val = bd->shift_lsbs ? *bd->shift_lsbs : 0;
    int32_t *samples = bd->raw_samples;
    unsigned int len = bd->block_length;

    for (smp = 0; smp < len; smp++) {
        int32_t sample = samples[smp];
        if ((unsigned int)sample & 0x80000000U) {
            samples[smp] = -((unsigned int)(-sample) << shift_val);
        } else {
            samples[smp] = (unsigned int)sample << shift_val;
        }
    }
}
