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
    // Variant 2: Strided Memory Access
    // Modified to write results using a strided access pattern (stride of 2, then fill in gaps)
    // This changes memory access order to simulate non-unit stride usage

    t1_inc_prev = 0;
    t2_inc_prev = 0;
    t1 = 1.0f;
    t2 = 1.0f;

    // First pass: write every second element starting at 0
    for (i = 0; i < 428; i += 2) {
        t1_inc_cur = 4 * (i % 4);
        t2_inc_cur = (8 + 3 * i) % 16;

        if (t1_inc_cur < t1_inc_prev)
            t1 *= 2;
        if (t2_inc_cur < t2_inc_prev)
            t2 *= 2;

        ff_aac_pow2sf_tab[i] = t1 * exp2_lut[t1_inc_cur];
        ff_aac_pow34sf_tab[i] = t2 * exp2_lut[t2_inc_cur];

        t1_inc_prev = t1_inc_cur;
        t2_inc_prev = t2_inc_cur;
    }

    // Second pass: fill in the odd indices with proper state continuity
    // Reinitialize state tracking variables and replay full sequence
    t1_inc_prev = 0;
    t2_inc_prev = 0;
    t1 = 1.0f;
    t2 = 1.0f;

    for (i = 1; i < 428; i += 2) {
        t1_inc_cur = 4 * (i % 4);
        t2_inc_cur = (8 + 3 * i) % 16;

        if (t1_inc_cur < t1_inc_prev)
            t1 *= 2;
        if (t2_inc_cur < t2_inc_prev)
            t2 *= 2;

        ff_aac_pow2sf_tab[i] = t1 * exp2_lut[t1_inc_cur];
        ff_aac_pow34sf_tab[i] = t2 * exp2_lut[t2_inc_cur];

        t1_inc_prev = t1_inc_cur;
        t2_inc_prev = t2_inc_cur;
    }
}
