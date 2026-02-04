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
    int idx = i / 2;
    t1_inc_cur = 4 * (idx % 4);
    t2_inc_cur = (8 + 3*idx) % 16;

    if (i == 0 || t1_inc_cur < t1_inc_prev)
        t1 *= 2;
    if (i == 0 || t2_inc_cur < t2_inc_prev)
        t2 *= 2;

    ff_aac_pow2sf_tab[idx] = t1 * exp2_lut[t1_inc_cur];
    ff_aac_pow34sf_tab[idx] = t2 * exp2_lut[t2_inc_cur];

    t1_inc_prev = t1_inc_cur;
    t2_inc_prev = t2_inc_cur;

    if (idx + 1 < 428) {
        int next_idx = idx + 1;
        int t1_inc_next = 4 * (next_idx % 4);
        int t2_inc_next = (8 + 3*next_idx) % 16;
        if (t1_inc_next < t1_inc_cur)
            t1 *= 2;
        if (t2_inc_next < t2_inc_cur)
            t2 *= 2;
        ff_aac_pow2sf_tab[next_idx] = t1 * exp2_lut[t1_inc_next];
        ff_aac_pow34sf_tab[next_idx] = t2 * exp2_lut[t2_inc_next];
        t1_inc_prev = t1_inc_next;
        t2_inc_prev = t2_inc_next;
    }
}
}
