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
    // Variant 1: Consecutive and coalesced memory access with unrolling by 2
    // Memory accesses are now more sequential in terms of lookup usage, reducing modulo overhead
    t1_inc_prev = 0;
    t2_inc_prev = 0;
    for (i = 0; i < 428; i += 2) {
        int idx1 = i;
        int idx2 = i + 1;

        // Compute increments for first iteration
        t1_inc_cur = 4 * (idx1 % 4);
        t2_inc_cur = (8 + 3 * idx1) % 16;
        if (t1_inc_cur < t1_inc_prev)
            t1 *= 2;
        if (t2_inc_cur < t2_inc_prev)
            t2 *= 2;
        ff_aac_pow2sf_tab[idx1] = t1 * exp2_lut[t1_inc_cur];
        ff_aac_pow34sf_tab[idx1] = t2 * exp2_lut[t2_inc_cur];
        int t1_inc_cur1 = t1_inc_cur;
        int t2_inc_cur1 = t2_inc_cur;

        // Second iteration if within bounds
        if (idx2 < 428) {
            t1_inc_cur = 4 * (idx2 % 4);
            t2_inc_cur = (8 + 3 * idx2) % 16;
            if (t1_inc_cur < t1_inc_cur1)
                t1 *= 2;
            if (t2_inc_cur < t2_inc_cur1)
                t2 *= 2;
            ff_aac_pow2sf_tab[idx2] = t1 * exp2_lut[t1_inc_cur];
            ff_aac_pow34sf_tab[idx2] = t2 * exp2_lut[t2_inc_cur];
        }

        t1_inc_prev = t1_inc_cur;
        t2_inc_prev = t2_inc_cur;
    }
}
