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
    int offset = 0;
    tmp[offset + 0] = 0 * src1[-2] + -1 * src1[-1] + 5 * src1[0] + 5 * src1[1] + -1 * src1[2] + 0 * src1[3];
    tmp[offset + 1] = 0 * src1[-1] + -1 * src1[0] + 5 * src1[1] + 5 * src1[2] + -1 * src1[3] + 0 * src1[4];
    tmp[offset + 2] = 0 * src1[0] + -1 * src1[1] + 5 * src1[2] + 5 * src1[3] + -1 * src1[4] + 0 * src1[5];
    tmp[offset + 3] = 0 * src1[1] + -1 * src1[2] + 5 * src1[3] + 5 * src1[4] + -1 * src1[5] + 0 * src1[6];
    tmp[offset + 4] = 0 * src1[2] + -1 * src1[3] + 5 * src1[4] + 5 * src1[5] + -1 * src1[6] + 0 * src1[7];
    tmp[offset + 5] = 0 * src1[3] + -1 * src1[4] + 5 * src1[5] + 5 * src1[6] + -1 * src1[7] + 0 * src1[8];
    tmp[offset + 6] = 0 * src1[4] + -1 * src1[5] + 5 * src1[6] + 5 * src1[7] + -1 * src1[8] + 0 * src1[9];
    tmp[offset + 7] = 0 * src1[5] + -1 * src1[6] + 5 * src1[7] + 5 * src1[8] + -1 * src1[9] + 0 * src1[10];

    offset += 8;
    tmp[offset + 0] = 0 * src1[4] + -1 * src1[5] + 5 * src1[6] + 5 * src1[7] + -1 * src1[8] + 0 * src1[9];
    tmp[offset + 1] = 0 * src1[5] + -1 * src1[6] + 5 * src1[7] + 5 * src1[8] + -1 * src1[9] + 0 * src1[10];
    tmp[offset + 2] = 0 * src1[6] + -1 * src1[7] + 5 * src1[8] + 5 * src1[9] + -1 * src1[10] + 0 * src1[11];
    tmp[offset + 3] = 0 * src1[7] + -1 * src1[8] + 5 * src1[9] + 5 * src1[10] + -1 * src1[11] + 0 * src1[12];
    tmp[offset + 4] = 0 * src1[8] + -1 * src1[9] + 5 * src1[10] + 5 * src1[11] + -1 * src1[12] + 0 * src1[13];
    tmp[offset + 5] = 0 * src1[9] + -1 * src1[10] + 5 * src1[11] + 5 * src1[12] + -1 * src1[13] + 0 * src1[14];
    tmp[offset + 6] = 0 * src1[10] + -1 * src1[11] + 5 * src1[12] + 5 * src1[13] + -1 * src1[14] + 0 * src1[15];
    tmp[offset + 7] = 0 * src1[11] + -1 * src1[12] + 5 * src1[13] + 5 * src1[14] + -1 * src1[15] + 0 * src1[16];

    tmp += 16;
    src1 += 2 * srcStride;
}
}
