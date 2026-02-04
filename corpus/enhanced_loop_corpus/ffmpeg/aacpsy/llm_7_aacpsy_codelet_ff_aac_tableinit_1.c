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
    float t1_next = t1;
    float t2_next = t2;
    int t1_inc_prev_next = t1_inc_prev;
    int t2_inc_prev_next = t2_inc_prev;

    for (i = 0; i < 428; i++) {
        int t1_inc_cur_local = 4 * (i % 4);
        int t2_inc_cur_local = (8 + 3 * i) % 16;

        float t1_use = t1_next;
        float t2_use = t2_next;

        if (t1_inc_cur_local < t1_inc_prev_next)
            t1_next *= 2;
        if (t2_inc_cur_local < t2_inc_prev_next)
            t2_next *= 2;

        ff_aac_pow2sf_tab[i] = t1_use * exp2_lut[t1_inc_cur_local];
        ff_aac_pow34sf_tab[i] = t2_use * exp2_lut[t2_inc_cur_local];

        t1_inc_prev_next = t1_inc_cur_local;
        t2_inc_prev_next = t2_inc_cur_local;
    }

    t1 = t1_next;
    t2 = t2_next;
    t1_inc_prev = t1_inc_prev_next;
    t2_inc_prev = t2_inc_prev_next;
}
