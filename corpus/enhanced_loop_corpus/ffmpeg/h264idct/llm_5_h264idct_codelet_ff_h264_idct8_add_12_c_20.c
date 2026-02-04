#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int32_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    unsigned int local[8];
    for (int j = 0; j < 8; j++) {
        local[j] = block[i + j * 8];
    }

    const unsigned int a0 = local[0] + local[4];
    const unsigned int a2 = local[0] - local[4];
    const unsigned int a4 = (local[2] >> 1) - local[6];
    const unsigned int a6 = (local[6] >> 1) + local[2];
    const unsigned int b0 = a0 + a6;
    const unsigned int b2 = a2 + a4;
    const unsigned int b4 = a2 - a4;
    const unsigned int b6 = a0 - a6;

    const int a1 = -local[3] + local[5] - local[7] - (local[7] >> 1);
    const int a3 = local[1] + local[7] - local[3] - (local[3] >> 1);
    const int a5 = -local[1] + local[7] + local[5] + (local[5] >> 1);
    const int a7 = local[3] + local[5] + local[1] + (local[1] >> 1);

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
}
}
