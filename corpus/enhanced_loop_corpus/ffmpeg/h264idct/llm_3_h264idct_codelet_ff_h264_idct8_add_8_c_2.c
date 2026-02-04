#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const int stride = 8;
int offsets[8] = {0, 8, 16, 24, 32, 40, 48, 56};
for (i = 0; i < 8; i++) {
    const int base = i * stride;
    const unsigned int a0 = block[base + offsets[0]] + (unsigned int)block[base + offsets[4]];
    const unsigned int a2 = block[base + offsets[0]] - (unsigned int)block[base + offsets[4]];
    const unsigned int a4 = (block[base + offsets[2]] >> 1) - (unsigned int)block[base + offsets[6]];
    const unsigned int a6 = (block[base + offsets[6]] >> 1) + (unsigned int)block[base + offsets[2]];
    const unsigned int b0 = a0 + a6;
    const unsigned int b2 = a2 + a4;
    const unsigned int b4 = a2 - a4;
    const unsigned int b6 = a0 - a6;
    const int a1 = -block[base + offsets[3]] + (unsigned int)block[base + offsets[5]] - block[base + offsets[7]] - (block[base + offsets[7]] >> 1);
    const int a3 = block[base + offsets[1]] + (unsigned int)block[base + offsets[7]] - block[base + offsets[3]] - (block[base + offsets[3]] >> 1);
    const int a5 = -block[base + offsets[1]] + (unsigned int)block[base + offsets[7]] + block[base + offsets[5]] + (block[base + offsets[5]] >> 1);
    const int a7 = block[base + offsets[3]] + (unsigned int)block[base + offsets[5]] + block[base + offsets[1]] + (block[base + offsets[1]] >> 1);
    const int b1 = (a7 >> 2) + (unsigned int)a1;
    const int b3 = (unsigned int)a3 + (a5 >> 2);
    const int b5 = (a3 >> 2) - (unsigned int)a5;
    const int b7 = (unsigned int)a7 - (a1 >> 2);
    block[base + offsets[0]] = b0 + b7;
    block[base + offsets[7]] = b0 - b7;
    block[base + offsets[1]] = b2 + b5;
    block[base + offsets[6]] = b2 - b5;
    block[base + offsets[2]] = b4 + b3;
    block[base + offsets[5]] = b4 - b3;
    block[base + offsets[3]] = b6 + b1;
    block[base + offsets[4]] = b6 - b1;
}
}
