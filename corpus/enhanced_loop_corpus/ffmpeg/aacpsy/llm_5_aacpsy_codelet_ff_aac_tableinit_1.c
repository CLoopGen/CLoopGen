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
// Precompute increments and use unswitched control with combined update logic
int update_t1, update_t2;
for (i = 0; i < 428; i++) {
    t1_inc_cur = 4 * (i % 4);
    t2_inc_cur = (8 + 3 * i) % 16;

    // Replace conditional state changes with flag-based arithmetic
    update_t1 = (t1_inc_cur < t1_inc_prev);
    update_t2 = (t2_inc_cur < t2_inc_prev);

    t1 = t1 * (1 + update_t1);  // doubles t1 if update_t1 is 1, else unchanged
    t2 = t2 * (1 + update_t2);

    ff_aac_pow2sf_tab[i] = t1 * exp2_lut[t1_inc_cur];
    ff_aac_pow34sf_tab[i] = t2 * exp2_lut[t2_inc_cur];

    t1_inc_prev = t1_inc_cur;
    t2_inc_prev = t2_inc_cur;
}
}
