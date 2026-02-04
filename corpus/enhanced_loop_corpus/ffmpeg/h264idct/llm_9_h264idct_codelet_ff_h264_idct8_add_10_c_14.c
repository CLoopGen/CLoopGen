#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int32_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i += 2) {
    const unsigned int a0 = block[i % 8 + 0 * 8] + (unsigned int)block[i % 8 + 4 * 8];
    const unsigned int a2 = block[i % 8 + 0 * 8] - (unsigned int)block[i % 8 + 4 * 8];
    const unsigned int a4 = (block[i % 8 + 2 * 8] >> 1) - (unsigned int)block[i % 8 + 6 * 8];
    const unsigned int a6 = (block[i % 8 + 6 * 8] >> 1) + (unsigned int)block[i % 8 + 2 * 8];
    const unsigned int b0 = a0 + a6;
    const unsigned int b2 = a2 + a4;
    const unsigned int b4 = a2 - a4;
    const unsigned int b6 = a0 - a6;

    const int a1 = -block[i % 8 + 3 * 8] + (unsigned int)block[i % 8 + 5 * 8] - block[i % 8 + 7 * 8] - ((block[i % 8 + 7 * 8]) >> 1);
    const int a3 = block[i % 8 + 1 * 8] + (unsigned int)block[i % 8 + 7 * 8] - block[i % 8 + 3 * 8] - ((block[i % 8 + 3 * 8]) >> 1);
    const int a5 = -block[i % 8 + 1 * 8] + (unsigned int)block[i % 8 + 7 * 8] + block[i % 8 + 5 * 8] + ((block[i % 8 + 5 * 8]) >> 1);
    const int a7 = block[i % 8 + 3 * 8] + (unsigned int)block[i % 8 + 5 * 8] + block[i % 8 + 1 * 8] + ((block[i % 8 + 1 * 8]) >> 1);

    const int b1 = (a7 >> 2) + (unsigned int)a1;
    const int b3 = (unsigned int)a3 + (a5 >> 2);
    const int b5 = (a3 >> 2) - (unsigned int)a5;
    const int b7 = (unsigned int)a7 - (a1 >> 2);

    block[i % 8 + 0 * 8] = b0 + b7;
    block[i % 8 + 7 * 8] = b0 - b7;
    block[i % 8 + 1 * 8] = b2 + b5;
    block[i % 8 + 6 * 8] = b2 - b5;
    block[i % 8 + 2 * 8] = b4 + b3;
    block[i % 8 + 5 * 8] = b4 - b3;
    block[i % 8 + 3 * 8] = b6 + b1;
    block[i % 8 + 4 * 8] = b6 - b1;

    if (i + 1 < 16) {
        const unsigned int c0 = block[(i+1) % 8 + 0 * 8] + (unsigned int)block[(i+1) % 8 + 4 * 8];
        const unsigned int c6 = (block[(i+1) % 8 + 6 * 8] >> 1) + (unsigned int)block[(i+1) % 8 + 2 * 8];
        const unsigned int d0 = c0 + c6;
        const unsigned int d6 = c0 - c6;
        const int c7 = block[(i+1) % 8 + 3 * 8] + (unsigned int)block[(i+1) % 8 + 5 * 8] + block[(i+1) % 8 + 1 * 8] + ((block[(i+1) % 8 + 1 * 8]) >> 1);
        const int c1 = -block[(i+1) % 8 + 3 * 8] + (unsigned int)block[(i+1) % 8 + 5 * 8] - block[(i+1) % 8 + 7 * 8] - ((block[(i+1) % 8 + 7 * 8]) >> 1);
        const int d1 = (c7 >> 2) + (unsigned int)c1;
        const int d7 = (unsigned int)c7 - (c1 >> 2);
        block[(i+1) % 8 + 0 * 8] = d0 + d7;
        block[(i+1) % 8 + 7 * 8] = d0 - d7;
        block[(i+1) % 8 + 3 * 8] = d6 + d1;
        block[(i+1) % 8 + 4 * 8] = d6 - d1;
    }
}
}
