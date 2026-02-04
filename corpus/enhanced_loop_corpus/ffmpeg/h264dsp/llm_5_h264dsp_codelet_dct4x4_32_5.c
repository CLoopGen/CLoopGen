#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *coef;
extern int i;
extern int32_t tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    const int base = i * 4;
    const int c0 = coef[base + 0];
    const int c1 = coef[base + 1];
    const int c2 = coef[base + 2];
    const int c3 = coef[base + 3];

    const int sum_03 = c0 + c3;
    const int sum_12 = c1 + c2;
    const int diff_03 = c0 - c3;
    const int diff_12 = c1 - c2;

    tmp[i + 0] = sum_03 + sum_12;
    
    if (diff_03 > 0) {
        tmp[i + 4] = 2 * diff_03 + diff_12;
    } else {
        tmp[i + 4] = diff_12; // Simplified path when condition fails
    }

    tmp[i + 8] = sum_03 - sum_12;

    if (diff_12 != 0) {
        tmp[i + 12] = diff_03 - 2 * diff_12;
    } else {
        tmp[i + 12] = diff_03; // Avoid multiplication when unnecessary
    }
}
}
