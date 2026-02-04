#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) {
    const int idx = i % 8;
    const unsigned int a0 = (i < 8) ? block[idx + 0 * 8] + (unsigned int)block[idx + 4 * 8] :
                             block[idx + 1 * 8] + (unsigned int)block[idx + 5 * 8];
    const unsigned int a2 = (i < 8) ? block[idx + 0 * 8] - (unsigned int)block[idx + 4 * 8] :
                             block[idx + 1 * 8] - (unsigned int)block[idx + 5 * 8];
    const unsigned int a4 = (i < 8) ? (block[idx + 2 * 8] >> 1) - (unsigned int)block[idx + 6 * 8] :
                             (block[idx + 3 * 8] >> 1) - (unsigned int)block[idx + 7 * 8];
    const unsigned int a6 = (i < 8) ? (block[idx + 6 * 8] >> 1) + (unsigned int)block[idx + 2 * 8] :
                             (block[idx + 7 * 8] >> 1) + (unsigned int)block[idx + 3 * 8];
    const unsigned int b0 = a0 + a6;
    const unsigned int b2 = a2 + a4;
    const unsigned int b4 = a2 - a4;
    const unsigned int b6 = a0 - a6;

    const int a1 = (i < 8) ? -block[idx + 3 * 8] + (unsigned int)block[idx + 5 * 8] - block[idx + 7 * 8] - (block[idx + 7 * 8] >> 1) :
                            block[idx + 0 * 8] - (unsigned int)block[idx + 4 * 8];
    const int a3 = (i < 8) ? block[idx + 1 * 8] + (unsigned int)block[idx + 7 * 8] - block[idx + 3 * 8] - (block[idx + 3 * 8] >> 1) :
                            block[idx + 1 * 8] + (unsigned int)block[idx + 5 * 8];
    const int a5 = (i < 8) ? -block[idx + 1 * 8] + (unsigned int)block[idx + 7 * 8] + block[idx + 5 * 8] + (block[idx + 5 * 8] >> 1) :
                            block[idx + 2 * 8] - (unsigned int)block[idx + 6 * 8];
    const int a7 = (i < 8) ? block[idx + 3 * 8] + (unsigned int)block[idx + 5 * 8] + block[idx + 1 * 8] + (block[idx + 1 * 8] >> 1) :
                            block[idx + 3 * 8] + (unsigned int)block[idx + 7 * 8];

    const int b1 = (i < 8) ? (a7 >> 2) + (unsigned int)a1 : (a7 >> 1) + a1;
    const int b3 = (i < 8) ? (unsigned int)a3 + (a5 >> 2) : (unsigned int)a3 + (a5 >> 1);
    const int b5 = (i < 8) ? (a3 >> 2) - (unsigned int)a5 : (a3 >> 1) - (unsigned int)a5;
    const int b7 = (i < 8) ? (unsigned int)a7 - (a1 >> 2) : (unsigned int)a7 - (a1 >> 1);

    if (i < 8) {
        block[idx + 0 * 8] = b0 + b7;
        block[idx + 7 * 8] = b0 - b7;
        block[idx + 1 * 8] = b2 + b5;
        block[idx + 6 * 8] = b2 - b5;
        block[idx + 2 * 8] = b4 + b3;
        block[idx + 5 * 8] = b4 - b3;
        block[idx + 3 * 8] = b6 + b1;
        block[idx + 4 * 8] = b6 - b1;
    } else {
        block[idx + 0 * 8] ^= b0 ^ b7;
        block[idx + 1 * 8] ^= b2 ^ b5;
        block[idx + 2 * 8] ^= b4 ^ b3;
        block[idx + 3 * 8] ^= b6 ^ b1;
    }
}
}
