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
    float local_t1 = t1;
    float local_t2 = t2;
    int prev_t1_inc = t1_inc_prev;
    int prev_t2_inc = t2_inc_prev;

    for (i = 0; i < 428; i++) {
        int curr_t1_inc = 4 * (i % 4);
        int curr_t2_inc = (8 + 3 * i) % 16;

        if (curr_t1_inc < prev_t1_inc)
            local_t1 *= 2;
        if (curr_t2_inc < prev_t2_inc)
            local_t2 *= 2;

        ff_aac_pow2sf_tab[i] = local_t1 * exp2_lut[curr_t1_inc];
        ff_aac_pow34sf_tab[i] = local_t2 * exp2_lut[curr_t2_inc];

        prev_t1_inc = curr_t1_inc;
        prev_t2_inc = curr_t2_inc;
    }

    t1 = local_t1;
    t2 = local_t2;
    t1_inc_prev = prev_t1_inc;
    t2_inc_prev = prev_t2_inc;
}
