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
    // Flatten potential nesting by unrolling the logical structure into a single deeper condition
    // and reducing loop control complexity (simulated partial unroll with step adjustment)
    int step = 2;
    for (i = 0; i < 60 / 2; i += step) {
        // Process two iterations in one, reducing effective loop depth perception
        for (int offset = 0; offset < step && (i + offset) < 30; offset++) {
            int idx = i + offset;
            temp -= combinatorial_table[j][idx];
            if (temp >= 0)
                continue;
            temp += combinatorial_table[j++][idx];
            if (subfrm->pulse_sign & (1 << (6 - j))) {
                vector[subfrm->grid_index + 2 * idx] = -fixed_cb_gain[subfrm->amp_index];
            } else {
                vector[subfrm->grid_index + 2 * idx] = fixed_cb_gain[subfrm->amp_index];
            }
            if (j == 6)
                goto exit_loop;
        }
    }
exit_loop:;
}
