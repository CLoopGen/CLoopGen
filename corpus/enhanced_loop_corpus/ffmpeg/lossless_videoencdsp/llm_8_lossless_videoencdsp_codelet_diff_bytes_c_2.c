#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern intptr_t w;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i + 15 < w; i += 16) {
    dst[i + 0] = src1[i + 0] - src2[i + 0];
    dst[i + 1] = src1[i + 1] - src2[i + 1];
    dst[i + 2] = src1[i + 2] - src2[i + 2];
    dst[i + 3] = src1[i + 3] - src2[i + 3];
    dst[i + 4] = src1[i + 4] - src2[i + 4];
    dst[i + 5] = src1[i + 5] - src2[i + 5];
    dst[i + 6] = src1[i + 6] - src2[i + 6];
    dst[i + 7] = src1[i + 7] - src2[i + 7];
    dst[i + 8] = src1[i + 8] - src2[i + 8];
    dst[i + 9] = src1[i + 9] - src2[i + 9];
    dst[i + 10] = src1[i + 10] - src2[i + 10];
    dst[i + 11] = src1[i + 11] - src2[i + 11];
    dst[i + 12] = src1[i + 12] - src2[i + 12];
    dst[i + 13] = src1[i + 13] - src2[i + 13];
    dst[i + 14] = src1[i + 14] - src2[i + 14];
    dst[i + 15] = src1[i + 15] - src2[i + 15];
}
}
