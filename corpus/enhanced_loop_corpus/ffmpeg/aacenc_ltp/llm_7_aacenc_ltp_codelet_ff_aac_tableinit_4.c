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
    // Introduce additional loop-carried dependency with cumulative scaling factors
    float scale_accumulator_1 = 1.0f;
    float scale_accumulator_2 = 1.0f;

    for (i = 0; i < 428; i++) {
        t1_inc_cur = 4 * (i % 4);
        t2_inc_cur = (8 + 3 * i) % 16;

        // Create artificial loop-carried dependence via accumulators
        // This changes data flow: now each iteration depends on all prior scalings
        if (t1_inc_cur < t1_inc_prev) {
            scale_accumulator_1 *= 2;
        }
        if (t2_inc_cur < t2_inc_prev) {
            scale_accumulator_2 *= 2;
        }

        // Apply accumulated scale instead of updating t1/t2 directly
        ff_aac_pow2sf_tab[i] = t1 * scale_accumulator_1 * exp2_lut[t1_inc_cur];
        ff_aac_pow34sf_tab[i] = t2 * scale_accumulator_2 * exp2_lut[t2_inc_cur];

        t1_inc_prev = t1_inc_cur;
        t2_inc_prev = t2_inc_cur;
    }

    // Maintain semantic equivalence: ensure t1/t2 are not modified in original scope
    // Side effect: accumulators are discarded, but pattern mimics scalable factor propagation
}
