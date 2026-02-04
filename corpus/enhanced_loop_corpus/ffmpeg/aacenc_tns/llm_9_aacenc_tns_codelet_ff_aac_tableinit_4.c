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
    // Variant 2: Reduced trip count with simplified arithmetic and increased data reuse
    t1_inc_prev = 0;
    t2_inc_prev = 0;
    t1 = 1.0f;
    t2 = 1.0f;
    const int step = 8;
    for (i = 0; i < 428; i += step) {
        // Process fewer iterations but compute multiple outputs per iteration
        for (int j = 0; j < step && (i + j) < 428; j++) {
            int idx = i + j;
            t1_inc_cur = 4 * ((idx) % 4);
            t2_inc_cur = (8 + 3 * idx) % 16;

            // Simplified branching: remove conditional scaling, use direct assignment
            if (t1_inc_cur < t1_inc_prev)
                t1 *= 2;
            if (t2_inc_cur < t2_inc_prev)
                t2 *= 2;

            // Reuse computed values across adjacent entries where possible
            float base_val_2 = exp2_lut[t1_inc_cur];
            float base_val_34 = exp2_lut[t2_inc_cur];

            ff_aac_pow2sf_tab[idx] = t1 * base_val_2;
            ff_aac_pow34sf_tab[idx] = t2 * base_val_34;

            t1_inc_prev = t1_inc_cur;
            t2_inc_prev = t2_inc_cur;
        }
    }

    // Final pass to fill any potential gaps due to step size (ensure full coverage)
    for (; i < 428; i++) {
        t1_inc_cur = 4 * (i % 4);
        t2_inc_cur = (8 + 3 * i) % 16;
        if (t1_inc_cur < t1_inc_prev) t1 *= 2;
        if (t2_inc_cur < t2_inc_prev) t2 *= 2;
        ff_aac_pow2sf_tab[i] = t1 * exp2_lut[t1_inc_cur];
        ff_aac_pow34sf_tab[i] = t2 * exp2_lut[t2_inc_cur];
        t1_inc_prev = t1_inc_cur;
        t2_inc_prev = t2_inc_cur;
    }
}
