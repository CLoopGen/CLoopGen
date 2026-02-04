#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp[16];
extern int32_t *input;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int prev_z0 = 0;
for (i = 0; i < 4; i++) {
    const int offset = 4 * i;
    const int z0 = input[offset + 0] + input[offset + 1] + prev_z0;
    const int z1 = input[offset + 0] - input[offset + 1];
    const int z2 = input[offset + 2] - input[offset + 3];
    const int z3 = input[offset + 2] + input[offset + 3];
    temp[offset + 0] = z0 + z3;
    temp[offset + 1] = z0 - z3;
    temp[offset + 2] = z1 - z2;
    temp[offset + 3] = z1 + z2;
    prev_z0 = z0;
}
}
