#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *lp;
extern int lp_half_order;
extern int i;
extern int f1[11];
extern int f2[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int prev_f1 = f1[0];
int prev_f2 = f2[0];
for (i = 1; i < lp_half_order + 1; i++) {
    int curr_f1 = f1[i];
    int curr_f2 = f2[i];
    int ff1 = curr_f1 + prev_f1;
    int ff2 = curr_f2 - prev_f2;
    ff1 += 1 << 10;
    lp[i] = (ff1 + ff2) >> 11;
    lp[(lp_half_order << 1) + 1 - i] = (ff1 - ff2) >> 11;
    prev_f1 = curr_f1;
    prev_f2 = curr_f2;
}
}
