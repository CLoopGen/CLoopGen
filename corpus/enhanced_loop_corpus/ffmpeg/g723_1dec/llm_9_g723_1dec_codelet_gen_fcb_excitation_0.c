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
    for (i = 0; i < 60 / 3; i += 2) {
        int diff1 = combinatorial_table[j][i];
        temp -= diff1;
        if (temp < 0) {
            temp += diff1;
            int sign_mask = (1 << (6 - j));
            int gain_val = fixed_cb_gain[subfrm->amp_index];
            vector[subfrm->grid_index + 2 * i] = (subfrm->pulse_sign & sign_mask) ? -gain_val : gain_val;
            if (++j == 6) break;
        }
        if (i + 1 < 20) {
            int diff2 = combinatorial_table[j][i+1];
            temp -= diff2;
            if (temp < 0) {
                temp += diff2;
                int sign_mask = (1 << (6 - j));
                int gain_val = fixed_cb_gain[subfrm->amp_index];
                vector[subfrm->grid_index + 2 * (i+1)] = (subfrm->pulse_sign & sign_mask) ? -gain_val : gain_val;
                if (++j == 6) break;
            }
        }
    }
}
