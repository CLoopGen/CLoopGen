#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
unsigned int prev_b0 = 0, prev_b1 = 0;
for (i = 0; i < 8; i++) {
    const unsigned int load_offset = i * 8;
    const unsigned int val0 = block[load_offset + 0] + (i > 0 ? prev_b0 : 0);
    const unsigned int val4 = block[load_offset + 4 * 8];
    const unsigned int a0 = val0 + val4;
    const unsigned int a2 = val0 - val4;
    const unsigned int a4 = (block[load_offset + 2 * 8] >> 1) - (unsigned int)block[load_offset + 6 * 8];
    const unsigned int a6 = (block[load_offset + 6 * 8] >> 1) + (unsigned int)block[load_offset + 2 * 8];
    const unsigned int b0 = a0 + a6;
    const unsigned int b2 = a2 + a4;
    const unsigned int b4 = a2 - a4;
    const unsigned int b6 = a0 - a6;
    const int a1 = -block[load_offset + 3 * 8] + (unsigned int)block[load_offset + 5 * 8] - block[load_offset + 7 * 8] - (block[load_offset + 7 * 8] >> 1);
    const int a3 = block[load_offset + 1 * 8] + (unsigned int)block[load_offset + 7 * 8] - block[load_offset + 3 * 8] - (block[load_offset + 3 * 8] >> 1);
    const int a5 = -block[load_offset + 1 * 8] + (unsigned int)block[load_offset + 7 * 8] + block[load_offset + 5 * 8] + (block[load_offset + 5 * 8] >> 1);
    const int a7 = block[load_offset + 3 * 8] + (unsigned int)block[load_offset + 5 * 8] + block[load_offset + 1 * 8] + (block[load_offset + 1 * 8] >> 1);
    const int b1 = (a7 >> 2) + (unsigned int)a1;
    const int b3 = (unsigned int)a3 + (a5 >> 2);
    const int b5 = (a3 >> 2) - (unsigned int)a5;
    const int b7 = (unsigned int)a7 - (a1 >> 2);
    block[load_offset + 0 * 8] = b0 + b7;
    block[load_offset + 7 * 8] = b0 - b7;
    block[load_offset + 1 * 8] = b2 + b5;
    block[load_offset + 6 * 8] = b2 - b5;
    block[load_offset + 2 * 8] = b4 + b3;
    block[load_offset + 5 * 8] = b4 - b3;
    block[load_offset + 3 * 8] = b6 + b1;
    block[load_offset + 4 * 8] = b6 - b1;
    prev_b0 = b0;
    prev_b1 = b1;
}
}
