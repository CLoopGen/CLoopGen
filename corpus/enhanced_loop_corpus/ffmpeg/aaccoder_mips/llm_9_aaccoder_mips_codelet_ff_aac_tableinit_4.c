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
for (i = 0; i < 856; i += 2) {
    int idx1 = i % 428;
    int idx2 = (i + 1) % 428;
    t1_inc_cur = (i / 2) % 16;
    t2_inc_cur = (12 + 5 * i) % 16;
    float factor1 = (t1_inc_cur < 8) ? 1.0f : 2.0f;
    float factor2 = (t2_inc_cur < 8) ? 1.0f : 2.0f;
    if (t1_inc_cur < t1_inc_prev)
        t1 *= 2;
    if (t2_inc_cur < t2_inc_prev)
        t2 *= 2;
    ff_aac_pow2sf_tab[idx1] = t1 * exp2_lut[t1_inc_cur & 0xF] * factor1;
    ff_aac_pow34sf_tab[idx1] = t2 * exp2_lut[t2_inc_cur] * factor2;
    ff_aac_pow2sf_tab[idx2] = t1 * exp2_lut[(t1_inc_cur + 1) & 0xF] * factor1;
    ff_aac_pow34sf_tab[idx2] = t2 * exp2_lut[(t2_inc_cur + 1) & 0xF] * factor2;
    t1_inc_prev = t1_inc_cur;
    t2_inc_prev = t2_inc_cur;
}
}
