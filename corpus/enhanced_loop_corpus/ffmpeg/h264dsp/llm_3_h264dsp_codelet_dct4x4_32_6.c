#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *coef;
extern int i;
extern int32_t tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[4][4] = {
    {0, 3, 1, 2},
    {4, 7, 5, 6},
    {8, 11, 9, 10},
    {12, 15, 13, 14}
};
for (i = 0; i < 4; i++) {
    const int* idx = indices[i];
    const int z0 = tmp[idx[0]] + tmp[idx[1]];
    const int z1 = tmp[idx[2]] + tmp[idx[3]];
    const int z2 = tmp[idx[0]] - tmp[idx[1]];
    const int z3 = tmp[idx[2]] - tmp[idx[3]];
    coef[idx[0]] = z0 + z1;
    coef[idx[2]] = 2 * z2 + z3;
    coef[idx[1]] = z0 - z1;
    coef[idx[3]] = z2 - 2 * z3;
}
}
