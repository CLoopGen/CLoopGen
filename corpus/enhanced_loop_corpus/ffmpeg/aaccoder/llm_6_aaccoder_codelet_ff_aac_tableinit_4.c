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
    t1_inc_prev = 0;
    t2_inc_prev = 0;
    for (i = 0; i < 428; i++) {
        int temp_t1_inc = 4 * (i % 4);
        int temp_t2_inc = (8 + 3 * i) % 16;
        float new_t1 = t1;
        float new_t2 = t2;

        if (temp_t1_inc < t1_inc_prev)
            new_t1 *= 2;
        if (temp_t2_inc < t2_inc_prev)
            new_t2 *= 2;

        ff_aac_pow2sf_tab[i] = new_t1 * exp2_lut[temp_t1_inc];
        ff_aac_pow34sf_tab[i] = new_t2 * exp2_lut[temp_t2_inc];

        t1 = new_t1;
        t2 = new_t2;
        t1_inc_prev = temp_t1_inc;
        t2_inc_prev = temp_t2_inc;
    }
}
