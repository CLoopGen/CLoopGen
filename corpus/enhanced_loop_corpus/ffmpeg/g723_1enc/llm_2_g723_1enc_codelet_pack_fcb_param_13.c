#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct G723_1_Subframe {
    int ad_cb_lag;
    int ad_cb_gain;
    int dirac_train;
    int pulse_sign;
    int grid_index;
    int amp_index;
    int pulse_pos;
} G723_1_Subframe;

typedef struct FCBParam {
    int min_err;
    int amp_index;
    int grid_index;
    int dirac_train;
    int pulse_pos[6];
    int pulse_sign[6];
} FCBParam;

extern  int32_t combinatorial_table[6][30];
extern G723_1_Subframe *subfrm;
extern FCBParam *optim;
extern int16_t *buf;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Precomputed Index
    int base_index = optim->grid_index;
    for (i = 0; i < 60 >> 1; i++) {
        int idx = base_index + (i << 1);
        int val = buf[idx];
        if (!val) {
            subfrm->pulse_pos += combinatorial_table[j][i];
        } else {
            subfrm->pulse_sign <<= 1;
            if (val < 0)
                subfrm->pulse_sign++;
            j++;
            if (j == 6)
                break;
        }
    }
}
