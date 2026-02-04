#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using pointer arithmetic
    int16_t *base = coef;
    for (i = 0; i < 4; i++) {
        const int a1 = base[i] + base[i + 12];
        const int b1 = base[i + 4] + base[i + 8];
        const int c1 = base[i + 4] - base[i + 8];
        const int d1 = base[i] - base[i + 12];
        base[i] = (a1 + b1 + 7) >> 4;
        base[i + 4] = ((c1 * 2217 + d1 * 5352 + 12000) >> 16) + !!d1;
        base[i + 8] = (a1 - b1 + 7) >> 4;
        base[i + 12] = (d1 * 2217 - c1 * 5352 + 51000) >> 16;
    }
}
