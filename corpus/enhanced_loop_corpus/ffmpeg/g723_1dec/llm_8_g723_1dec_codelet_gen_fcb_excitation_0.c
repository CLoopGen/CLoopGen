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

extern  int32_t combinatorial_table[6][30];
extern  int16_t fixed_cb_gain[24];
extern int16_t *vector;
extern G723_1_Subframe *subfrm;
extern int temp;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 60 / 4; i++) {
        temp -= combinatorial_table[j][2*i] + combinatorial_table[j][2*i+1];
        if (temp >= 0)
            continue;
        temp += combinatorial_table[j++][2*i];
        if (subfrm->pulse_sign & (1 << (6 - j))) {
            vector[subfrm->grid_index + 2 * i] = -fixed_cb_gain[subfrm->amp_index];
            vector[subfrm->grid_index + 2 * i + 1] = -fixed_cb_gain[subfrm->amp_index];
        } else {
            vector[subfrm->grid_index + 2 * i] = fixed_cb_gain[subfrm->amp_index];
            vector[subfrm->grid_index + 2 * i + 1] = fixed_cb_gain[subfrm->amp_index];
        }
        if (j == 6)
            break;
    }
}
