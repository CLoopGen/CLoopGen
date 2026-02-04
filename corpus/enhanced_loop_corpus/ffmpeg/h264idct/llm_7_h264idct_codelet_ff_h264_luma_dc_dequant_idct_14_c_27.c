#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp[16];
extern int32_t *input;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int prev_offset = 0;
for (i = 0; i < 4; i++) {
    const int idx = 4 * i;
    const int next_offset = (i < 3) ? 4 * (i + 1) : idx;
    const int z0 = input[idx + 0] + input[idx + 1];
    const int z1 = input[idx + 0] - input[idx + 1];
    const int z2 = input[idx + 2] - input[idx + 3];
    const int z3 = input[idx + 2] + input[idx + 3];
    temp[idx + 0] = z0 + z3;
    temp[idx + 1] = z0 - z3;
    temp[idx + 2] = z1 - z2;
    temp[idx + 3] = z1 + z2;
    if (i > 0) {
        temp[prev_offset + 0] += temp[idx + 3]; 
    }
    prev_offset = idx;
}
}
