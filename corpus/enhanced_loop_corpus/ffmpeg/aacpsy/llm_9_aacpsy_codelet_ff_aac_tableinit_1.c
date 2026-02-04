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
    // Variant 2: Reduced trip count with fused operations and simplified indexing logic
    t1_inc_prev = 0;
    t2_inc_prev = 0;
    // Reduce effective trip count by increasing step size, then compensate via inner micro-steps
    for (i = 0; i < 107; i++) {  // 107 * 4 = 428
        for (int offset = 0; offset < 4; offset++) {
            int idx = (i << 2) | offset;  // idx = 4*i + offset
            t1_inc_cur = 4 * offset;  // equivalent to 4*(idx%4) due to offset in [0,3]
            t2_inc_cur = (8 + 3 * idx) & 15;  // same as mod 16

            // Fused condition and update: reduce branches
            t1 *= (t1_inc_cur < t1_inc_prev) ? 2.0f : 1.0f;
            t2 *= (t2_inc_cur < t2_inc_prev) ? 2.0f : 1.0f;

            // Direct assignment using fused computation
            ff_aac_pow2sf_tab[idx] = t1 * exp2_lut[t1_inc_cur];
            ff_aac_pow34sf_tab[idx] = t2 * exp2_lut[t2_inc_cur];

            t1_inc_prev = t1_inc_cur;
            t2_inc_prev = t2_inc_cur;
        }
    }
}
