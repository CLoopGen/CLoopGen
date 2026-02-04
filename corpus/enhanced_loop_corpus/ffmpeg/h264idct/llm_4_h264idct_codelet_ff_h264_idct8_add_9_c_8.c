#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int32_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    const unsigned int temp1 = (unsigned int)block[i + 4 * 8];
    const unsigned int temp2 = (unsigned int)block[i + 6 * 8];
    const unsigned int temp3 = (unsigned int)block[i + 2 * 8];
    const unsigned int a0 = block[i + 0 * 8] + temp1;
    const unsigned int a2 = block[i + 0 * 8] - temp1;
    const unsigned int a4 = (temp3 >> 1) - temp2;
    const unsigned int a6 = (temp2 >> 1) + temp3;
    const unsigned int b0 = a0 + a6;
    const unsigned int b2 = a2 + a4;
    const unsigned int b4 = a2 - a4;
    const unsigned int b6 = a0 - a6;

    const int temp4 = block[i + 3 * 8];
    const int temp5 = block[i + 5 * 8];
    const int temp6 = block[i + 7 * 8];
    const int temp7 = block[i + 1 * 8];
    const int a1 = -temp4 + temp5 - temp6 - (temp6 >> 1);
    const int a3 = temp7 + temp6 - temp4 - (temp4 >> 1);
    const int a5 = -temp7 + temp6 + temp5 + (temp5 >> 1);
    const int a7 = temp4 + temp5 + temp7 + (temp7 >> 1);
    const int b1 = (a7 >> 2) + (unsigned int)a1;
    const int b3 = (unsigned int)a3 + (a5 >> 2);
    const int b5 = (a3 >> 2) - (unsigned int)a5;
    const int b7 = (unsigned int)a7 - (a1 >> 2);

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
