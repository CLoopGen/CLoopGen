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
    for (ltp_smp = ((*bd->ltp_lag - 2) > (0) ? (*bd->ltp_lag - 2) : (0)); ltp_smp < block_length; ltp_smp++) {
        int center = ltp_smp - *bd->ltp_lag;
        int begin = ((0) > (center - 2) ? (0) : (center - 2));
        int end = center + 3;
        int tab = 5 - (end - begin);
        int base;
        y = 1 << 6;
        if (begin < end) {
            for (int depth_level = 0; depth_level < 1; depth_level++) {
                for (base = begin; base < end; base++, tab++)
                    y += (uint64_t)((int64_t)(bd->ltp_gain[tab]) * (int64_t)(raw_samples[base]));
            }
        }
        raw_samples[ltp_smp] += y >> 7;
    }
}
