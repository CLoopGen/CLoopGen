#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp[16];
extern int32_t *input;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int stride = 16;
for (i = 0; i < 4; i++) {
    const int base_in = i * stride;
    const int base_temp = i * stride;
    const int z0 = input[base_in + 0] + input[base_in + 4];
    const int z1 = input[base_in + 0] - input[base_in + 4];
    const int z2 = input[base_in + 8] - input[base_in + 12];
    const int z3 = input[base_in + 8] + input[base_in + 12];
    temp[base_temp + 0] = z0 + z3;
    temp[base_temp + 4] = z0 - z3;
    temp[base_temp + 8] = z1 - z2;
    temp[base_temp + 12] = z1 + z2;
}
}
