#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;
extern int16_t tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    const int z0 = coef[i * 8 + 0] + coef[i * 8 + 7];
    const int z1 = coef[i * 8 + 1] + coef[i * 8 + 6];
    const int z2 = coef[i * 8 + 2] + coef[i * 8 + 5];
    const int z3 = coef[i * 8 + 3] + coef[i * 8 + 4];
    const int y0 = z0 + z3;
    const int y1 = z1 + z2;
    const int y2 = z0 - z3;
    const int y3 = z1 - z2;
    tmp[i + 0] = y0 + y1;
    tmp[i + 2] = y0 - y1;
    tmp[i + 4] = y2 + y3;
    tmp[i + 6] = y2 - y3;
}
}
