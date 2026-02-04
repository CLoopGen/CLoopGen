#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    const int z0 = 13 * (block[0 + 4 * (i % 4)] + block[2 + 4 * (i % 4)]);
    const int z1 = 13 * (block[0 + 4 * (i % 4)] - block[2 + 4 * (i % 4)]);
    const int z2 = 7 * block[1 + 4 * (i % 4)] - 17 * block[3 + 4 * (i % 4)];
    const int z3 = 17 * block[1 + 4 * (i % 4)] + 7 * block[3 + 4 * (i % 4)];
    block[0 + 4 * (i % 4)] = z0 + z3;
    block[1 + 4 * (i % 4)] = z1 + z2;
    block[2 + 4 * (i % 4)] = z1 - z2;
    block[3 + 4 * (i % 4)] = z0 - z3;
}
}
