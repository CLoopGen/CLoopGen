#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t (*src)[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; ++i) {
    int16_t *row = &src[i][0];
    const int a0 = 3 * row[1] - 2 * row[7];
    const int a1 = 3 * row[3] + 2 * row[5];
    const int a2 = 2 * row[3] - 3 * row[5];
    const int a3 = 2 * row[1] + 3 * row[7];
    const int b4 = 2 * (a0 + a1 + a3) + a1;
    const int b5 = 2 * (a0 - a1 + a2) + a0;
    const int b6 = 2 * (a3 - a2 - a1) + a3;
    const int b7 = 2 * (a0 - a2 - a3) - a2;
    const int a7 = 4 * row[2] - 10 * row[6];
    const int a6 = 4 * row[6] + 10 * row[2];
    const int a5 = 8 * (row[0] - row[4]) + 4;
    const int a4 = 8 * (row[0] + row[4]) + 4;
    const int b0 = a4 + a6;
    const int b1 = a5 + a7;
    const int b2 = a5 - a7;
    const int b3 = a4 - a6;
    row[0] = (b0 + b4) >> 3;
    row[1] = (b1 + b5) >> 3;
    row[2] = (b2 + b6) >> 3;
    row[3] = (b3 + b7) >> 3;
    row[4] = (b3 - b7) >> 3;
    row[5] = (b2 - b6) >> 3;
    row[6] = (b1 - b5) >> 3;
    row[7] = (b0 - b4) >> 3;
}
}
