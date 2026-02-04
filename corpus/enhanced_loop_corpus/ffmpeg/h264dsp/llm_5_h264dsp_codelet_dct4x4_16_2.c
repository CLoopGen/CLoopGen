#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;
extern int16_t tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    const int base = i * 4;
    const int c0 = coef[base + 0], c1 = coef[base + 1], c2 = coef[base + 2], c3 = coef[base + 3];

    const int z0 = c0 + c3;
    const int z1 = c1 + c2;
    const int z2 = c0 - c3;
    const int z3 = c1 - c2;

    tmp[i + 4 * 0] = z0 + z1;
    
    if (z2 > 0) {
        tmp[i + 4 * 1] = 2 * z2 + z3;
    } else {
        tmp[i + 4 * 1] = z3; // Simplified computation when z2 <= 0
    }

    tmp[i + 4 * 2] = z0 - z1;

    if (z3 != 0) {
        tmp[i + 4 * 3] = z2 - 2 * z3;
    } else {
        tmp[i + 4 * 3] = z2; // Avoid multiplication when unnecessary
    }
}
}
