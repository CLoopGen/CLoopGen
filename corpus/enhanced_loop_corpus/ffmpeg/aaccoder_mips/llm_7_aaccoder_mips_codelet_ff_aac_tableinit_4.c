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
    // Introduce additional loop-carried dependency via cumulative scaling factor
    float scale_accum = 1.0f;
    float t1_local = t1;
    float t2_local = t2;

    for (i = 0; i < 428; i++) {
        t1_inc_cur = 4 * (i % 4);
        t2_inc_cur = (8 + 3 * i) % 16;

        // Create a new RAW dependency: scale_accum affects both outputs
        if (t1_inc_cur < t1_inc_prev || t2_inc_cur < t2_inc_prev) {
            scale_accum *= 1.5f;  // Additional mutation factor
        }

        // Feed scale_accum into computations to create stronger data dependency
        if (t1_inc_cur < t1_inc_prev)
            t1_local *= 2;
        if (t2_inc_cur < t2_inc_prev)
            t2_local *= 2;

        ff_aac_pow2sf_tab[i] = t1_local * exp2_lut[t1_inc_cur] * scale_accum;
        ff_aac_pow34sf_tab[i] = t2_local * exp2_lut[t2_inc_cur] * scale_accum;

        t1_inc_prev = t1_inc_cur;
        t2_inc_prev = t2_inc_cur;
    }

    // Propagate local state back to globals
    t1 = t1_local;
    t2 = t2_local;
}
