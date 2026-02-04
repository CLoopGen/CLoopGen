#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float ff_aac_pow2sf_tab[428];
extern float ff_aac_pow34sf_tab[428];
extern int i;
extern  float exp2_lut[];
extern float t1;
extern float t2;
extern int t1_inc_cur;
extern int t2_inc_cur;
extern int t1_inc_prev;
extern int t2_inc_prev;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Loop Unrolling (factor of 2)
    // Arrays are accessed in a more sequential pattern by precomputing indices and reducing modulo operations.
    int idx1_prev = 0, idx2_prev = 0;
    for (i = 0; i < 428; i += 2) {
        int idx1_cur_0 = 4 * ((i + 0) % 4);
        int idx2_cur_0 = (8 + 3 * (i + 0)) % 16;

        if (idx1_cur_0 < idx1_prev)
            t1 *= 2;
        if (idx2_cur_0 < idx2_prev)
            t2 *= 2;

        ff_aac_pow2sf_tab[i + 0] = t1 * exp2_lut[idx1_cur_0];
        ff_aac_pow34sf_tab[i + 0] = t2 * exp2_lut[idx2_cur_0];

        idx1_prev = idx1_cur_0;
        idx2_prev = idx2_cur_0;

        // Handle second iteration if within bounds
        if (i + 1 < 428) {
            int idx1_cur_1 = 4 * ((i + 1) % 4);
            int idx2_cur_1 = (8 + 3 * (i + 1)) % 16;

            if (idx1_cur_1 < idx1_prev)
                t1 *= 2;
            if (idx2_cur_1 < idx2_prev)
                t2 *= 2;

            ff_aac_pow2sf_tab[i + 1] = t1 * exp2_lut[idx1_cur_1];
            ff_aac_pow34sf_tab[i + 1] = t2 * exp2_lut[idx2_cur_1];

            idx1_prev = idx1_cur_1;
            idx2_prev = idx2_cur_1;
        }
    }
}
