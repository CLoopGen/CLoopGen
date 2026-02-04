#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[4][4];
for (int j = 0; j < 4; j++) {
    indices[j][0] = j * 4 + 0;
    indices[j][1] = j * 4 + 1;
    indices[j][2] = j * 4 + 2;
    indices[j][3] = j * 4 + 3;
}
for (i = 0; i < 4; i++) {
    const int *idx = indices[i];
    const int a1 = (coef[idx[0]] + coef[idx[3]]) * 8;
    const int b1 = (coef[idx[1]] + coef[idx[2]]) * 8;
    const int c1 = (coef[idx[1]] - coef[idx[2]]) * 8;
    const int d1 = (coef[idx[0]] - coef[idx[3]]) * 8;
    coef[idx[0]] = a1 + b1;
    coef[idx[1]] = (c1 * 2217 + d1 * 5352 + 14500) >> 12;
    coef[idx[2]] = a1 - b1;
    coef[idx[3]] = (d1 * 2217 - c1 * 5352 + 7500) >> 12;
}
}
