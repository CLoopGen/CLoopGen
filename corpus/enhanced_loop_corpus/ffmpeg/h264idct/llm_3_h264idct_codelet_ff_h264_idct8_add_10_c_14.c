#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int32_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const int stride = 8;
int indices[8];
for (int j = 0; j < 8; j++) {
    indices[j] = j * stride;
}
for (i = 0; i < 8; i++) {
    const int base_idx = indices[i];
    const unsigned int a0 = block[base_idx + 0 * 8] + (unsigned int)block[base_idx + 4 * 8];
    const unsigned int a2 = block[base_idx + 0 * 8] - (unsigned int)block[base_idx + 4 * 8];
    const unsigned int a4 = (block[base_idx + 2 * 8] >> 1) - (unsigned int)block[base_idx + 6 * 8];
    const unsigned int a6 = (block[base_idx + 6 * 8] >> 1) + (unsigned int)block[base_idx + 2 * 8];
    const unsigned int b0 = a0 + a6;
    const unsigned int b2 = a2 + a4;
    const unsigned int b4 = a2 - a4;
    const unsigned int b6 = a0 - a6;
    const int a1 = -block[base_idx + 3 * 8] + (unsigned int)block[base_idx + 5 * 8] - block[base_idx + 7 * 8] - (block[base_idx + 7 * 8] >> 1);
    const int a3 = block[base_idx + 1 * 8] + (unsigned int)block[base_idx + 7 * 8] - block[base_idx + 3 * 8] - (block[base_idx + 3 * 8] >> 1);
    const int a5 = -block[base_idx + 1 * 8] + (unsigned int)block[base_idx + 7 * 8] + block[base_idx + 5 * 8] + (block[base_idx + 5 * 8] >> 1);
    const int a7 = block[base_idx + 3 * 8] + (unsigned int)block[base_idx + 5 * 8] + block[base_idx + 1 * 8] + (block[base_idx + 1 * 8] >> 1);
    const int b1 = (a7 >> 2) + (unsigned int)a1;
    const int b3 = (unsigned int)a3 + (a5 >> 2);
    const int b5 = (a3 >> 2) - (unsigned int)a5;
    const int b7 = (unsigned int)a7 - (a1 >> 2);
    block[base_idx + 0 * 8] = b0 + b7;
    block[base_idx + 7 * 8] = b0 - b7;
    block[base_idx + 1 * 8] = b2 + b5;
    block[base_idx + 6 * 8] = b2 - b5;
    block[base_idx + 2 * 8] = b4 + b3;
    block[base_idx + 5 * 8] = b4 - b3;
    block[base_idx + 3 * 8] = b6 + b1;
    block[base_idx + 4 * 8] = b6 - b1;
}
}
