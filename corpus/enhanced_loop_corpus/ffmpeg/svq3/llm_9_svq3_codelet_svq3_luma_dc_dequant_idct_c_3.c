#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *input;
extern int i;
extern int temp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    const int x0 = input[4 * i + 0];
    const int x1 = input[4 * i + 1];
    const int x2 = input[4 * i + 2];
    const int x3 = input[4 * i + 3];
    const int t0 = x0 + x2;
    const int t1 = x0 - x2;
    const int t2 = x1;
    const int t3 = x3;
    const int z0 = 13 * t0;
    const int z1 = 13 * t1;
    const int z2 = 7 * t2 - 17 * t3;
    const int z3 = 17 * t2 + 7 * t3;
    temp[4 * i + 0] = z0 + z3;
    temp[4 * i + 1] = z1 + z2;
    temp[4 * i + 2] = z1 - z2;
    temp[4 * i + 3] = z0 - z3;
}
}
