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
    float t1_local = t1;
    float t2_local = t2;
    int t1_inc_prev_local = t1_inc_prev;
    int t2_inc_prev_local = t2_inc_prev;

    for (i = 0; i < 428; i++) {
        int t1_inc_cur = 4 * (i % 4);
        int t2_inc_cur = (8 + 3 * i) % 16;

        if (t1_inc_cur < t1_inc_prev_local)
            t1_local *= 2;
        if (t2_inc_cur < t2_inc_prev_local)
            t2_local *= 2;

        ff_aac_pow2sf_tab[i] = t1_local * exp2_lut[t1_inc_cur];
        ff_aac_pow34sf_tab[i] = t2_local * exp2_lut[t2_inc_cur];

        t1_inc_prev_local = t1_inc_cur;
        t2_inc_prev_local = t2_inc_cur;
    }

    t1 = t1_local;
    t2 = t2_local;
    t1_inc_prev = t1_inc_prev_local;
    t2_inc_prev = t2_inc_prev_local;
}
