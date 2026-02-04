#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *coef;
extern int i;
extern int32_t tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        const int k = i * 2 + j;
        const int c0 = coef[k * 4 + 0], c1 = coef[k * 4 + 1];
        const int c2 = coef[k * 4 + 2], c3 = coef[k * 4 + 3];
        const int sum_03 = c0 + c3, sum_12 = c1 + c2;
        const int diff_03 = c0 - c3, diff_12 = c1 - c2;
        tmp[k + 4 * 0] = sum_03 + sum_12;
        tmp[k + 4 * 1] = (diff_03 << 1) + diff_12;
        tmp[k + 4 * 2] = sum_03 - sum_12;
        tmp[k + 4 * 3] = diff_03 - (diff_12 << 1);
    }
}
}
