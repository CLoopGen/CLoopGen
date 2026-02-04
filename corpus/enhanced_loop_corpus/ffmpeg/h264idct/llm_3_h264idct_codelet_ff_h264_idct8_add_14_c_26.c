#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int32_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[8] = {0, 2, 4, 6, 1, 3, 5, 7};
for (i = 0; i < 8; i++) {
    const int j = indices[i]; // Indirect access via index mapping
    const unsigned int a0 = block[j + 0 * 8] + (unsigned int)block[j + 4 * 8];
    const unsigned int a2 = block[j + 0 * 8] - (unsigned int)block[j + 4 * 8];
    const unsigned int a4 = (block[j + 2 * 8] >> 1) - (unsigned int)block[j + 6 * 8];
    const unsigned int a6 = (block[j + 6 * 8] >> 1) + (unsigned int)block[j + 2 * 8];
    const unsigned int b0 = a0 + a6;
    const unsigned int b2 = a2 + a4;
    const unsigned int b4 = a2 - a4;
    const unsigned int b6 = a0 - a6;
    const int a1 = -block[j + 3 * 8] + (unsigned int)block[j + 5 * 8] - block[j + 7 * 8] - (block[j + 7 * 8] >> 1);
    const int a3 = block[j + 1 * 8] + (unsigned int)block[j + 7 * 8] - block[j + 3 * 8] - (block[j + 3 * 8] >> 1);
    const int a5 = -block[j + 1 * 8] + (unsigned int)block[j + 7 * 8] + block[j + 5 * 8] + (block[j + 5 * 8] >> 1);
    const int a7 = block[j + 3 * 8] + (unsigned int)block[j + 5 * 8] + block[j + 1 * 8] + (block[j + 1 * 8] >> 1);
    const int b1 = (a7 >> 2) + (unsigned int)a1;
    const int b3 = (unsigned int)a3 + (a5 >> 2);
    const int b5 = (a3 >> 2) - (unsigned int)a5;
    const int b7 = (unsigned int)a7 - (a1 >> 2);
    block[j + 0 * 8] = b0 + b7;
    block[j + 7 * 8] = b0 - b7;
    block[j + 1 * 8] = b2 + b5;
    block[j + 6 * 8] = b2 - b5;
    block[j + 2 * 8] = b4 + b3;
    block[j + 5 * 8] = b4 - b3;
    block[j + 3 * 8] = b6 + b1;
    block[j + 4 * 8] = b6 - b1;
}
}
