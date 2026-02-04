#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp[16];
extern int32_t *input;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i += 4) {
    const int base_in = 4 * (i / 4);
    const int base_temp = i;
    const int z0 = input[base_in + 0] + input[base_in + 1];
    const int z1 = input[base_in + 0] - input[base_in + 1];
    const int z2 = input[base_in + 2] - input[base_in + 3];
    const int z3 = input[base_in + 2] + input[base_in + 3];
    temp[base_temp + 0] = z0 + z3;
    temp[base_temp + 1] = z0 - z3;
    temp[base_temp + 2] = z1 - z2;
    temp[base_temp + 3] = z1 + z2;
}
}
