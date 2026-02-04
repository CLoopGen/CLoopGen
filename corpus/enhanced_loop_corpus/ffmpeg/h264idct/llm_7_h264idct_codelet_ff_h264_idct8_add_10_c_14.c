#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int32_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    const unsigned int x0 = block[i + 0 * 8], x1 = block[i + 1 * 8];
    const unsigned int x2 = block[i + 2 * 8], x3 = block[i + 3 * 8];
    const unsigned int x4 = block[i + 4 * 8], x5 = block[i + 5 * 8];
    const unsigned int x6 = block[i + 6 * 8], x7 = block[i + 7 * 8];

    const unsigned int a0 = x0 + x4;
    const unsigned int a2 = x0 - x4;
    const unsigned int a4 = (x2 >> 1) - x6;
    const unsigned int a6 = (x6 >> 1) + x2;

    const unsigned int b0 = a0 + a6;
    const unsigned int b2 = a2 + a4;
    const unsigned int b4 = a2 - a4;
    const unsigned int b6 = a0 - a6;

    const int a1 = -x3 + x5 - x7 - (x7 >> 1);
    const int a3 = x1 + x7 - x3 - (x3 >> 1);
    const int a5 = -x1 + x7 + x5 + (x5 >> 1);
    const int a7 = x3 + x5 + x1 + (x1 >> 1);

    const int b1 = (a7 >> 2) + a1;
    const int b3 = a3 + (a5 >> 2);
    const int b5 = (a3 >> 2) - a5;
    const int b7 = a7 - (a1 >> 2);

    block[i + 0 * 8] = b0 + b7;
    block[i + 7 * 8] = b0 - b7;
    block[i + 1 * 8] = b2 + b5;
    block[i + 6 * 8] = b2 - b5;
    block[i + 2 * 8] = b4 + b3;
    block[i + 5 * 8] = b4 - b3;
    block[i + 3 * 8] = b6 + b1;
    block[i + 4 * 8] = b6 - b1;

    __asm__ volatile("" : "+m"(*block)); // Artificially introduce memory dependency to prevent reordering and create WAW/RAR hazards
}
}
