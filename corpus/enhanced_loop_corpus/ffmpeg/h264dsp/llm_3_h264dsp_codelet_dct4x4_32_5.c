#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *coef;
extern int i;
extern int32_t tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int stride = 4;
for (i = 0; i < 4; i++) {
    int access_pattern[4] = {0, 3, 1, 2};
    const int c0 = coef[i * stride + access_pattern[0]];
    const int c1 = coef[i * stride + access_pattern[1]];
    const int c2 = coef[i * stride + access_pattern[2]];
    const int c3 = coef[i * stride + access_pattern[3]];
    const int z0 = c0 + c1;
    const int z1 = c2 + c3;
    const int z2 = c0 - c1;
    const int z3 = c2 - c3;
    tmp[i + 4 * 0] = z0 + z1;
    tmp[i + 4 * 1] = 2 * z2 + z3;
    tmp[i + 4 * 2] = z0 - z1;
    tmp[i + 4 * 3] = z2 - 2 * z3;
}
}
