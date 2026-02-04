#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp[16];
extern int16_t *input;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    const int idx = 4 * i;
    const int a = input[idx + 0];
    const int b = input[idx + 1];
    const int c = input[idx + 2];
    const int d = input[idx + 3];
    const int z0_plus_z3 = (a + b) + (c + d);
    const int z0_minus_z3 = (a + b) - (c + d);
    const int z1_minus_z2 = (a - b) - (c - d);
    const int z1_plus_z2 = (a - b) + (c - d);
    temp[idx + 0] = z0_plus_z3;
    temp[idx + 1] = z0_minus_z3;
    temp[idx + 2] = z1_minus_z2;
    temp[idx + 3] = z1_plus_z2;
}
}
