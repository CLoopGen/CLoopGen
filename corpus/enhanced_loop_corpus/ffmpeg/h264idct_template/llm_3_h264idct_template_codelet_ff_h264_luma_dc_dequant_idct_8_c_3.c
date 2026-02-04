#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp[16];
extern int16_t *input;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[4] = {0, 4, 8, 12};
for (i = 0; i < 4; i++) {
    const int base = indices[i];
    const int z0 = input[base + 0] + input[base + 1];
    const int z1 = input[base + 0] - input[base + 1];
    const int z2 = input[base + 2] - input[base + 3];
    const int z3 = input[base + 2] + input[base + 3];
    temp[base + 0] = z0 + z3;
    temp[base + 1] = z0 - z3;
    temp[base + 2] = z1 - z2;
    temp[base + 3] = z1 + z2;
}
}
