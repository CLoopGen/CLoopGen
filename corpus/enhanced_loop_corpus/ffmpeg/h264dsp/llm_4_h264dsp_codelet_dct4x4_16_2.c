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
    if (i % 2 == 0) {
        const int z0 = coef[i * 4 + 0] + coef[i * 4 + 3];
        const int z1 = coef[i * 4 + 1] + coef[i * 4 + 2];
        const int z2 = coef[i * 4 + 0] - coef[i * 4 + 3];
        const int z3 = coef[i * 4 + 1] - coef[i * 4 + 2];
        tmp[i + 4 * 0] = z0 + z1;
        tmp[i + 4 * 1] = 2 * z2 + z3;
        tmp[i + 4 * 2] = z0 - z1;
        tmp[i + 4 * 3] = z2 - 2 * z3;
    } else {
        const int idx = i * 4;
        const int a = coef[idx + 0], b = coef[idx + 1], c = coef[idx + 2], d = coef[idx + 3];
        const int sum03 = a + d;
        const int sum12 = b + c;
        const int diff03 = a - d;
        const int diff12 = b - c;
        tmp[i + 0] = sum03 + sum12;
        tmp[i + 4] = 2 * diff03 + diff12;
        tmp[i + 8] = sum03 - sum12;
        tmp[i + 12] = diff03 - 2 * diff12;
    }
}
}
