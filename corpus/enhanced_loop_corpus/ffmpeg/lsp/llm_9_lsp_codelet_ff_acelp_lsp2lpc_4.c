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
int stride = 2;
for (i = 1; i < lp_half_order + 1; i += stride) {
    int ff1_prev = (i > 1) ? f1[i-1] : 0;
    int ff2_prev = (i > 1) ? f2[i-1] : 0;
    int ff1 = f1[i] + ff1_prev;
    int ff2 = f2[i] - ff2_prev;
    ff1 += 1 << 10;
    lp[i] = (ff1 + ff2) >> 11;
    lp[(lp_half_order << 1) + 1 - i] = (ff1 - ff2) >> 11;

    if (i + 1 < lp_half_order + 1) {
        int ff1_next = f1[i+1] + f1[i];
        int ff2_next = f2[i+1] - f2[i];
        ff1_next += 1 << 10;
        lp[i+1] = (ff1_next + ff2_next) >> 11;
        lp[(lp_half_order << 1) + 1 - (i+1)] = (ff1_next - ff2_next) >> 11;
    }
}
}
