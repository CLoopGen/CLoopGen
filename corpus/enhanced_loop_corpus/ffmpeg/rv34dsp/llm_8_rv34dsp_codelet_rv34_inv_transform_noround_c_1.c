#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int temp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    const int idx0 = 4 * 0 + (i % 4);
    const int idx1 = 4 * 1 + (i % 4);
    const int idx2 = 4 * 2 + (i % 4);
    const int idx3 = 4 * 3 + (i % 4);
    const int t0 = temp[idx0];
    const int t1 = temp[idx1];
    const int t2 = temp[idx2];
    const int t3 = temp[idx3];
    const int z0 = 39 * (t0 + t2);
    const int z1 = 39 * (t0 - t2);
    const int z2 = 21 * t1 - 51 * t3;
    const int z3 = 51 * t1 + 21 * t3;
    const int sum03 = z0 + z3;
    const int sum12 = z1 + z2;
    const int diff12 = z1 - z2;
    const int diff03 = z0 - z3;
    block[(i % 4) * 4 + 0] = sum03 >> 11;
    block[(i % 4) * 4 + 1] = sum12 >> 11;
    block[(i % 4) * 4 + 2] = diff12 >> 11;
    block[(i % 4) * 4 + 3] = diff03 >> 11;
}
}
