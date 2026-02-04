#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    const int idx0 = i + 0 * 4, idx1 = i + 1 * 4;
    const int idx2 = i + 2 * 4, idx3 = i + 3 * 4;
    const int a1 = coef[idx0] + coef[idx3];
    const int b1 = coef[idx1] + coef[idx2];
    const int c1 = coef[idx1] - coef[idx2];
    const int d1 = coef[idx0] - coef[idx3];
    const int sum = a1 + b1;
    const int diff = a1 - b1;
    const int term1 = (sum + 3) >> 3;
    const int term2 = (diff + 3) >> 3;
    const int sign_d1 = (d1 != 0);
    coef[idx0] = term1;
    coef[idx1] = ((c1 * 1060 + d1 * 2560 + 6000) >> 14) + sign_d1;
    coef[idx2] = term2;
    coef[idx3] = (d1 * 1060 - c1 * 2560 + 24000) >> 14;
}
}
