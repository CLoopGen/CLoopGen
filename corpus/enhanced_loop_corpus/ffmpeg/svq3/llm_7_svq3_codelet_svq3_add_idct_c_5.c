#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int prev_z0 = 0;
for (i = 0; i < 4; i++) {
    const int current_z0 = 13 * (block[0 + 4 * i] + block[2 + 4 * i]);
    const int z1 = 13 * (block[0 + 4 * i] - block[2 + 4 * i]);
    const int z2 = 7 * block[1 + 4 * i] - 17 * block[3 + 4 * i];
    const int z3 = 17 * block[1 + 4 * i] + 7 * block[3 + 4 * i];
    block[0 + 4 * i] = (i == 0) ? (current_z0 + z3) : (prev_z0 + z3);
    block[1 + 4 * i] = z1 + z2;
    block[2 + 4 * i] = z1 - z2;
    block[3 + 4 * i] = current_z0 - z3;
    prev_z0 = current_z0;
}
}
