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
for (i = 0; i < lp_half_order; i++) {
    int ff1 = f1[i] + f1[i + 1];
    int ff2 = f2[i + 1] - f2[i];
    ff1 += 1 << 10;
    lp[i + 1] = (ff1 + ff2) >> 11;
    lp[(lp_half_order << 1) - i] = (ff1 - ff2) >> 11;
}
}
