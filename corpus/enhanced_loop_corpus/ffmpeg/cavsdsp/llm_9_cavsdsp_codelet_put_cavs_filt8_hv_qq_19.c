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

    if (i + 1 < h + 8) {
        tmp[8] = 0 * src1[srcStride - 2] + -1 * src1[srcStride - 1] + 5 * src1[srcStride + 0] + 5 * src1[srcStride + 1] + -1 * src1[srcStride + 2] + 0 * src1[srcStride + 3];
        tmp[9] = 0 * src1[srcStride - 1] + -1 * src1[srcStride + 0] + 5 * src1[srcStride + 1] + 5 * src1[srcStride + 2] + -1 * src1[srcStride + 3] + 0 * src1[srcStride + 4];
        tmp[10] = 0 * src1[srcStride + 0] + -1 * src1[srcStride + 1] + 5 * src1[srcStride + 2] + 5 * src1[srcStride + 3] + -1 * src1[srcStride + 4] + 0 * src1[srcStride + 5];
        tmp[11] = 0 * src1[srcStride + 1] + -1 * src1[srcStride + 2] + 5 * src1[srcStride + 3] + 5 * src1[srcStride + 4] + -1 * src1[srcStride + 5] + 0 * src1[srcStride + 6];
        tmp[12] = 0 * src1[srcStride + 2] + -1 * src1[srcStride + 3] + 5 * src1[srcStride + 4] + 5 * src1[srcStride + 5] + -1 * src1[srcStride + 6] + 0 * src1[srcStride + 7];
        tmp[13] = 0 * src1[srcStride + 3] + -1 * src1[srcStride + 4] + 5 * src1[srcStride + 5] + 5 * src1[srcStride + 6] + -1 * src1[srcStride + 7] + 0 * src1[srcStride + 8];
        tmp[14] = 0 * src1[srcStride + 4] + -1 * src1[srcStride + 5] + 5 * src1[srcStride + 6] + 5 * src1[srcStride + 7] + -1 * src1[srcStride + 8] + 0 * src1[srcStride + 9];
        tmp[15] = 0 * src1[srcStride + 5] + -1 * src1[srcStride + 6] + 5 * src1[srcStride + 7] + 5 * src1[srcStride + 8] + -1 * src1[srcStride + 9] + 0 * src1[srcStride + 10];
        tmp += 16;
        src1 += 2 * srcStride;
    } else {
        tmp += 8;
        src1 += srcStride;
    }
}
}
