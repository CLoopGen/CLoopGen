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
    int step;
    for (i = 0; i < 856; i += 2) {
        step = i / 2;
        t1_inc_cur = 4 * (step % 4);
        t2_inc_cur = (8 + 3 * step) % 16;

        // Unconditionally update accumulators with pre-check logic fused
        t1 *= (t1_inc_cur < t1_inc_prev) ? 2 : 1;
        t2 *= (t2_inc_cur < t2_inc_prev) ? 2 : 1;

        ff_aac_pow2sf_tab[step] = t1 * exp2_lut[t1_inc_cur];
        ff_aac_pow34sf_tab[step] = t2 * exp2_lut[t2_inc_cur];

        t1_inc_prev = t1_inc_cur;
        t2_inc_prev = t2_inc_cur;
    }
}
