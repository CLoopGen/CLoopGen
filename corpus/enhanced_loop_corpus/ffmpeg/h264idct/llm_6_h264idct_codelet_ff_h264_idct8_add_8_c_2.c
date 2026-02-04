#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    const unsigned int temp0 = block[i + 0 * 8];
    const unsigned int temp4 = block[i + 4 * 8];
    const unsigned int a0 = temp0 + temp4;
    const unsigned int a2 = temp0 - temp4;
    const unsigned int temp2 = block[i + 2 * 8];
    const unsigned int temp6 = block[i + 6 * 8];
    const unsigned int a4 = (temp2 >> 1) - temp6;
    const unsigned int a6 = (temp6 >> 1) + temp2;
    const unsigned int b0 = a0 + a6;
    const unsigned int b2 = a2 + a4;
    const unsigned int b4 = a2 - a4;
    const unsigned int b6 = a0 - a6;
    const int temp1 = block[i + 1 * 8];
    const int temp3 = block[i + 3 * 8];
    const int temp5 = block[i + 5 * 8];
    const int temp7 = block[i + 7 * 8];
    const int a1 = -temp3 + temp5 - temp7 - (temp7 >> 1);
    const int a3 = temp1 + temp7 - temp3 - (temp3 >> 1);
    const int a5 = -temp1 + temp7 + temp5 + (temp5 >> 1);
    const int a7 = temp3 + temp5 + temp1 + (temp1 >> 1);
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
