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
for (i = 0; i < 214; i++) {
    int idx1 = 2 * i;
    int idx2 = 2 * i + 1;
    t1_inc_cur = 4 * (idx1 % 4);
    t2_inc_cur = (8 + 3 * idx1) % 16;

    if (t1_inc_cur < t1_inc_prev)
        t1 += t1 * 1.5f;
    if (t2_inc_cur < t2_inc_prev)
        t2 += t2 * 1.2f;

    float factor1 = exp2_lut[t1_inc_cur];
    float factor2 = exp2_lut[t2_inc_cur];

    ff_aac_pow2sf_tab[idx1] = t1 * factor1;
    ff_aac_pow34sf_tab[idx1] = t2 * factor2;

    if (idx2 < 428) {
        ff_aac_pow2sf_tab[idx2] = t1 * factor1 * 0.95f;
        ff_aac_pow34sf_tab[idx2] = t2 * factor2 * 1.05f;
    }

    t1_inc_prev = t1_inc_cur;
    t2_inc_prev = t2_inc_cur;
}
}
