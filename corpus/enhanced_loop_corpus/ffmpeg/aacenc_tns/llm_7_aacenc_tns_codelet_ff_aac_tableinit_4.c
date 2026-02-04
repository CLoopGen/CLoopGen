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
    // Introduce loop-carried dependence with delayed indexing
    // and reorganize computation to create a cumulative dependency chain

    float t1_local = t1;
    float t2_local = t2;
    int t1_inc_prev_local = t1_inc_prev;
    int t2_inc_prev_local = t2_inc_prev;

    // Process two elements per iteration with unrolling-like pattern
    // creating intra-loop dependencies and changing access pattern

    for (i = 0; i < 428; i += 2) {
        int base_idx1 = i;
        int base_idx2 = i + 1;

        int t1_inc_cur1 = 4 * (base_idx1 % 4);
        int t2_inc_cur1 = (8 + 3 * base_idx1) % 16;

        // Make second iteration depend on first within the same step
        if (t1_inc_cur1 < t1_inc_prev_local)
            t1_local *= 2;
        if (t2_inc_cur1 < t2_inc_prev_local)
            t2_local *= 2;

        ff_aac_pow2sf_tab[base_idx1] = t1_local * exp2_lut[t1_inc_cur1];
        ff_aac_pow34sf_tab[base_idx1] = t2_local * exp2_lut[t2_inc_cur1];

        t1_inc_prev_local = t1_inc_cur1;
        t2_inc_prev_local = t2_inc_cur1;

        // Second element depends on updates from first (introduced RAW dependence)
        if (base_idx2 >= 428) break;

        int t1_inc_cur2 = 4 * (base_idx2 % 4);
        int t2_inc_cur2 = (8 + 3 * base_idx2) % 16;

        if (t1_inc_cur2 < t1_inc_prev_local)
            t1_local *= 2;
        if (t2_inc_cur2 < t2_inc_prev_local)
            t2_local *= 2;

        ff_aac_pow2sf_tab[base_idx2] = t1_local * exp2_lut[t1_inc_cur2];
        ff_aac_pow34sf_tab[base_idx2] = t2_local * exp2_lut[t2_inc_cur2];

        t1_inc_prev_local = t1_inc_cur2;
        t2_inc_prev_local = t2_inc_cur2;
    }

    // Update globals after full loop execution
    t1 = t1_local;
    t2 = t2_local;
    t1_inc_prev = t1_inc_prev_local;
    t2_inc_prev = t2_inc_prev_local;
}
