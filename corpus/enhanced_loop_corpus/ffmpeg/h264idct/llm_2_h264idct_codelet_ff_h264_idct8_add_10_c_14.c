#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int32_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    const int idx = i * 8;
    const unsigned int a0 = block[idx + 0] + (unsigned int)block[idx + 32];
    const unsigned int a2 = block[idx + 0] - (unsigned int)block[idx + 32];
    const unsigned int a4 = (block[idx + 16] >> 1) - (unsigned int)block[idx + 48];
    const unsigned int a6 = (block[idx + 48] >> 1) + (unsigned int)block[idx + 16];
    const unsigned int b0 = a0 + a6;
    const unsigned int b2 = a2 + a4;
    const unsigned int b4 = a2 - a4;
    const unsigned int b6 = a0 - a6;
    const int a1 = -block[idx + 24] + (unsigned int)block[idx + 40] - block[idx + 56] - (block[idx + 56] >> 1);
    const int a3 = block[idx + 8] + (unsigned int)block[idx + 56] - block[idx + 24] - (block[idx + 24] >> 1);
    const int a5 = -block[idx + 8] + (unsigned int)block[idx + 56] + block[idx + 40] + (block[idx + 40] >> 1);
    const int a7 = block[idx + 24] + (unsigned int)block[idx + 40] + block[idx + 8] + (block[idx + 8] >> 1);
    const int b1 = (a7 >> 2) + (unsigned int)a1;
    const int b3 = (unsigned int)a3 + (a5 >> 2);
    const int b5 = (a3 >> 2) - (unsigned int)a5;
    const int b7 = (unsigned int)a7 - (a1 >> 2);
    block[idx + 0] = b0 + b7;
    block[idx + 56] = b0 - b7;
    block[idx + 8] = b2 + b5;
    block[idx + 48] = b2 - b5;
    block[idx + 16] = b4 + b3;
    block[idx + 40] = b4 - b3;
    block[idx + 24] = b6 + b1;
    block[idx + 32] = b6 - b1;
}
}
