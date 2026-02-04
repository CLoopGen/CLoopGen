#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t (*src)[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    const int temp1 = src[i][1], temp7 = src[i][7];
    const int a0 = 3 * temp1 - 2 * temp7;
    const int a3 = 2 * temp1 + 3 * temp7;

    const int temp3 = src[i][3], temp5 = src[i][5];
    const int a1 = 3 * temp3 + 2 * temp5;
    const int a2 = 2 * temp3 - 3 * temp5;

    const int b4 = 2 * (a0 + a1 + a3) + a1;
    const int b5 = 2 * (a0 - a1 + a2) + a0;
    const int b6 = 2 * (a3 - a2 - a1) + a3;
    const int b7 = 2 * (a0 - a2 - a3) - a2;

    const int temp2 = src[i][2], temp6 = src[i][6];
    const int a7 = 4 * temp2 - 10 * temp6;
    const int a6 = 4 * temp6 + 10 * temp2;

    const int temp0 = src[i][0], temp4 = src[i][4];
    const int a5 = 8 * (temp0 - temp4) + 4;
    const int a4 = 8 * (temp0 + temp4) + 4;

    const int b0 = a4 + a6;
    const int b1 = a5 + a7;
    const int b2 = a5 - a7;
    const int b3 = a4 - a6;

    src[i][0] = (b0 + b4) >> 3;
    src[i][1] = (b1 + b5) >> 3;
    src[i][2] = (b2 + b6) >> 3;
    src[i][3] = (b3 + b7) >> 3;
    src[i][4] = (b3 - b7) >> 3;
    src[i][5] = (b2 - b6) >> 3;
    src[i][6] = (b1 - b5) >> 3;
    src[i][7] = (b0 - b4) >> 3;
}
}
