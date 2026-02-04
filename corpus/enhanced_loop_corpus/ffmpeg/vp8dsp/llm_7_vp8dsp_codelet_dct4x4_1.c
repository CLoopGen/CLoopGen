#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp[4][4];
for (i = 0; i < 4; i++) {
    const int idx0 = i * 4 + 0;
    const int idx1 = i * 4 + 1;
    const int idx2 = i * 4 + 2;
    const int idx3 = i * 4 + 3;

    const int a1 = (coef[idx0] + coef[idx3]) * 8;
    const int b1 = (coef[idx1] + coef[idx2]) * 8;
    const int c1 = (coef[idx1] - coef[idx2]) * 8;
    const int d1 = (coef[idx0] - coef[idx3]) * 8;

    temp[i][0] = a1 + b1;
    temp[i][1] = (c1 * 2217 + d1 * 5352 + 14500) >> 12;
    temp[i][2] = a1 - b1;
    temp[i][3] = (d1 * 2217 - c1 * 5352 + 7500) >> 12;
}

for (i = 0; i < 4; i++) {
    const int base = i * 4;
    coef[base + 0] = temp[i][0];
    coef[base + 1] = temp[i][1];
    coef[base + 2] = temp[i][2];
    coef[base + 3] = temp[i][3];
}
}
