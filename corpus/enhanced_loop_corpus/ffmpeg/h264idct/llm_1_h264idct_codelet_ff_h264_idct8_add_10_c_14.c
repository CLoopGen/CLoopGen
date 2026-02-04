#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int32_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) { // Reduce effective loop range and process two elements per iteration
    const unsigned int a0_0 = block[i + 0 * 8] + (unsigned int)block[i + 4 * 8];
    const unsigned int a2_0 = block[i + 0 * 8] - (unsigned int)block[i + 4 * 8];
    const unsigned int a4_0 = (block[i + 2 * 8] >> 1) - (unsigned int)block[i + 6 * 8];
    const unsigned int a6_0 = (block[i + 6 * 8] >> 1) + (unsigned int)block[i + 2 * 8];
    const unsigned int b0_0 = a0_0 + a6_0;
    const unsigned int b2_0 = a2_0 + a4_0;
    const unsigned int b4_0 = a2_0 - a4_0;
    const unsigned int b6_0 = a0_0 - a6_0;
    const int a1_0 = -block[i + 3 * 8] + (unsigned int)block[i + 5 * 8] - block[i + 7 * 8] - (block[i + 7 * 8] >> 1);
    const int a3_0 = block[i + 1 * 8] + (unsigned int)block[i + 7 * 8] - block[i + 3 * 8] - (block[i + 3 * 8] >> 1);
    const int a5_0 = -block[i + 1 * 8] + (unsigned int)block[i + 7 * 8] + block[i + 5 * 8] + (block[i + 5 * 8] >> 1);
    const int a7_0 = block[i + 3 * 8] + (unsigned int)block[i + 5 * 8] + block[i + 1 * 8] + (block[i + 1 * 8] >> 1);
    const int b1_0 = (a7_0 >> 2) + (unsigned int)a1_0;
    const int b3_0 = (unsigned int)a3_0 + (a5_0 >> 2);
    const int b5_0 = (a3_0 >> 2) - (unsigned int)a5_0;
    const int b7_0 = (unsigned int)a7_0 - (a1_0 >> 2);

    const unsigned int a0_1 = block[(i+4) + 0 * 8] + (unsigned int)block[(i+4) + 4 * 8];
    const unsigned int a2_1 = block[(i+4) + 0 * 8] - (unsigned int)block[(i+4) + 4 * 8];
    const unsigned int a4_1 = (block[(i+4) + 2 * 8] >> 1) - (unsigned int)block[(i+4) + 6 * 8];
    const unsigned int a6_1 = (block[(i+4) + 6 * 8] >> 1) + (unsigned int)block[(i+4) + 2 * 8];
    const unsigned int b0_1 = a0_1 + a6_1;
    const unsigned int b2_1 = a2_1 + a4_1;
    const unsigned int b4_1 = a2_1 - a4_1;
    const unsigned int b6_1 = a0_1 - a6_1;
    const int a1_1 = -block[(i+4) + 3 * 8] + (unsigned int)block[(i+4) + 5 * 8] - block[(i+4) + 7 * 8] - (block[(i+4) + 7 * 8] >> 1);
    const int a3_1 = block[(i+4) + 1 * 8] + (unsigned int)block[(i+4) + 7 * 8] - block[(i+4) + 3 * 8] - (block[(i+4) + 3 * 8] >> 1);
    const int a5_1 = -block[(i+4) + 1 * 8] + (unsigned int)block[(i+4) + 7 * 8] + block[(i+4) + 5 * 8] + (block[(i+4) + 5 * 8] >> 1);
    const int a7_1 = block[(i+4) + 3 * 8] + (unsigned int)block[(i+4) + 5 * 8] + block[(i+4) + 1 * 8] + (block[(i+4) + 1 * 8] >> 1);
    const int b1_1 = (a7_1 >> 2) + (unsigned int)a1_1;
    const int b3_1 = (unsigned int)a3_1 + (a5_1 >> 2);
    const int b5_1 = (a3_1 >> 2) - (unsigned int)a5_1;
    const int b7_1 = (unsigned int)a7_1 - (a1_1 >> 2);

    block[i + 0 * 8] = b0_0 + b7_0;
    block[i + 7 * 8] = b0_0 - b7_0;
    block[i + 1 * 8] = b2_0 + b5_0;
    block[i + 6 * 8] = b2_0 - b5_0;
    block[i + 2 * 8] = b4_0 + b3_0;
    block[i + 5 * 8] = b4_0 - b3_0;
    block[i + 3 * 8] = b6_0 + b1_0;
    block[i + 4 * 8] = b6_0 - b1_0;

    block[(i+4) + 0 * 8] = b0_1 + b7_1;
    block[(i+4) + 7 * 8] = b0_1 - b7_1;
    block[(i+4) + 1 * 8] = b2_1 + b5_1;
    block[(i+4) + 6 * 8] = b2_1 - b5_1;
    block[(i+4) + 2 * 8] = b4_1 + b3_1;
    block[(i+4) + 5 * 8] = b4_1 - b3_1;
    block[(i+4) + 3 * 8] = b6_1 + b1_1;
    block[(i+4) + 4 * 8] = b6_1 - b1_1;
}
}
