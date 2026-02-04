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
    const int t0 = tmp[i * 4 + 0], t1 = tmp[i * 4 + 1];
    const int t2 = tmp[i * 4 + 2], t3 = tmp[i * 4 + 3];
    const int z0 = t0 + t3;
    const int z1 = t1 + t2;
    const int z2 = t0 - t3;
    const int z3 = t1 - t2;
    const int w0 = z0 + z1;
    const int w1 = z0 - z1;
    const int w2 = 2 * z2 + z3;
    const int w3 = z2 - 2 * z3;
    coef[i * 4 + 0] = w0;
    coef[i * 4 + 1] = w2;
    coef[i * 4 + 2] = w1;
    coef[i * 4 + 3] = w3;
}
}
