#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int stride;
extern int i;
extern int tblk[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++) {
    int a0 = tblk[i * 8 + 0], a1 = tblk[i * 8 + 1], a2 = tblk[i * 8 + 2], a3 = tblk[i * 8 + 3];
    int a4 = tblk[i * 8 + 4], a5 = tblk[i * 8 + 5], a6 = tblk[i * 8 + 6], a7 = tblk[i * 8 + 7];

    int sum1 = a0 + a1 + a2 + a3;
    int sum2 = a4 + a5 + a6 + a7;

    dst[0] = ((7 * sum1 + 3 * sum2) + 64) >> 7;
    dst[1] = ((7 * (a0 - a2) + 3 * (a4 - a6)) + 64) >> 7;
    dst += stride;

    dst[0] = ((7 * (a1 - a3) + 3 * (a5 - a7)) + 64) >> 7;
    dst[1] = ((7 * (a0 - a1 - a2 + a3) + 3 * (a4 - a5 - a6 + a7)) + 64) >> 7;
    dst += stride;
}
}
