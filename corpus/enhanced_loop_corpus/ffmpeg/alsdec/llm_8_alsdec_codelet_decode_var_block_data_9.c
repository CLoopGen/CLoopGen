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
extern unsigned int block_length;
extern int64_t y;
extern int32_t *raw_samples;
extern int ltp_smp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ltp_smp = ((*bd->ltp_lag - 4) > (0) ? (*bd->ltp_lag - 4) : (0)); ltp_smp < block_length; ltp_smp += 2) {
        int center = ltp_smp - *bd->ltp_lag;
        int begin = ((0) > (center - 3) ? (0) : (center - 3));
        int end = center + 4;
        int tab = 7 - (end - begin);
        int base;
        y = 1 << 5;
        for (base = begin; base < end; base++, tab++) {
            y += (uint64_t)((int64_t)(bd->ltp_gain[tab]) * (int64_t)(raw_samples[base]));
            y += (uint64_t)((int64_t)(bd->ltp_gain[tab]) * (int64_t)(raw_samples[base] >> 1)); // Increased arithmetic intensity
        }
        raw_samples[ltp_smp] += y >> 6;
        if (ltp_smp + 1 < block_length)
            raw_samples[ltp_smp + 1] += y >> 6;
    }
}
