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
    // Variant 2: Consecutive write with indirect (permuted) read indices via lookup table
    int index_map[428];
    for (int j = 0; j < 428; j++) {
        index_map[j] = (7 * j + 13) % 428; // Linear congruential permutation
    }

    t1_inc_prev = 0;
    t2_inc_prev = 0;
    t1 = 1.0f;
    t2 = 1.0f;

    for (i = 0; i < 428; i++) {
        int idx = index_map[i]; // Indirect access index

        t1_inc_cur = 4 * (idx % 4);
        t2_inc_cur = (8 + 3 * idx) % 16;

        if (t1_inc_cur < t1_inc_prev)
            t1 *= 2;
        if (t2_inc_cur < t2_inc_prev)
            t2 *= 2;

        ff_aac_pow2sf_tab[idx] = t1 * exp2_lut[t1_inc_cur];
        ff_aac_pow34sf_tab[idx] = t2 * exp2_lut[t2_inc_cur];

        t1_inc_prev = t1_inc_cur;
        t2_inc_prev = t2_inc_cur;
    }
}
