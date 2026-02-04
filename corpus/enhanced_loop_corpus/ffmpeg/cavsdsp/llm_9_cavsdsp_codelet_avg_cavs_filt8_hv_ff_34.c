#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src1;
extern ptrdiff_t srcStride;
extern int16_t *tmp;
extern  int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h + 8; i += 2) {
    tmp[0] = 0 * src1[-2] + -1 * src1[-1] + 5 * src1[0] + 5 * src1[1] + -1 * src1[2] + 0 * src1[3];
    tmp[1] = 0 * src1[-1] + -1 * src1[0] + 5 * src1[1] + 5 * src1[2] + -1 * src1[3] + 0 * src1[4];
    tmp[2] = 0 * src1[0] + -1 * src1[1] + 5 * src1[2] + 5 * src1[3] + -1 * src1[4] + 0 * src1[5];
    tmp[3] = 0 * src1[1] + -1 * src1[2] + 5 * src1[3] + 5 * src1[4] + -1 * src1[5] + 0 * src1[6];
    tmp[4] = 0 * src1[2] + -1 * src1[3] + 5 * src1[4] + 5 * src1[5] + -1 * src1[6] + 0 * src1[7];
    tmp[5] = 0 * src1[3] + -1 * src1[4] + 5 * src1[5] + 5 * src1[6] + -1 * src1[7] + 0 * src1[8];
    tmp[6] = 0 * src1[4] + -1 * src1[5] + 5 * src1[6] + 5 * src1[7] + -1 * src1[8] + 0 * src1[9];
    tmp[7] = 0 * src1[5] + -1 * src1[6] + 5 * src1[7] + 5 * src1[8] + -1 * src1[9] + 0 * src1[10];

    tmp[8] = 0 * src1[3 + srcStride] + -1 * src1[4 + srcStride] + 5 * src1[5 + srcStride] + 5 * src1[6 + srcStride] + -1 * src1[7 + srcStride] + 0 * src1[8 + srcStride];
    tmp[9] = 0 * src1[4 + srcStride] + -1 * src1[5 + srcStride] + 5 * src1[6 + srcStride] + 5 * src1[7 + srcStride] + -1 * src1[8 + srcStride] + 0 * src1[9 + srcStride];
    tmp[10] = 0 * src1[5 + srcStride] + -1 * src1[6 + srcStride] + 5 * src1[7 + srcStride] + 5 * src1[8 + srcStride] + -1 * src1[9 + srcStride] + 0 * src1[10 + srcStride];
    tmp[11] = 0 * src1[6 + srcStride] + -1 * src1[7 + srcStride] + 5 * src1[8 + srcStride] + 5 * src1[9 + srcStride] + -1 * src1[10 + srcStride] + 0 * src1[11 + srcStride];
    tmp[12] = 0 * src1[7 + srcStride] + -1 * src1[8 + srcStride] + 5 * src1[9 + srcStride] + 5 * src1[10 + srcStride] + -1 * src1[11 + srcStride] + 0 * src1[12 + srcStride];
    tmp[13] = 0 * src1[8 + srcStride] + -1 * src1[9 + srcStride] + 5 * src1[10 + srcStride] + 5 * src1[11 + srcStride] + -1 * src1[12 + srcStride] + 0 * src1[13 + srcStride];
    tmp[14] = 0 * src1[9 + srcStride] + -1 * src1[10 + srcStride] + 5 * src1[11 + srcStride] + 5 * src1[12 + srcStride] + -1 * src1[13 + srcStride] + 0 * src1[14 + srcStride];
    tmp[15] = 0 * src1[10 + srcStride] + -1 * src1[11 + srcStride] + 5 * src1[12 + srcStride] + 5 * src1[13 + srcStride] + -1 * src1[14 + srcStride] + 0 * src1[15 + srcStride];

    tmp += 16;
    src1 += 2 * srcStride;
}
}
