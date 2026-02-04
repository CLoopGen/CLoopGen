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
for (i = 0; i < h + 2; i += 2) {
    tmp[0] = -1 * src1[-2] + -2 * src1[-1] + 96 * src1[0] + 42 * src1[1] + -7 * src1[2];
    tmp[1] = -1 * src1[-1] + -2 * src1[0] + 96 * src1[1] + 42 * src1[2] + -7 * src1[3];
    tmp[2] = -1 * src1[0] + -2 * src1[1] + 96 * src1[2] + 42 * src1[3] + -7 * src1[4];
    tmp[3] = -1 * src1[1] + -2 * src1[2] + 96 * src1[3] + 42 * src1[4] + -7 * src1[5];
    tmp[4] = -1 * src1[2] + -2 * src1[3] + 96 * src1[4] + 42 * src1[5] + -7 * src1[6];
    tmp[5] = -1 * src1[3] + -2 * src1[4] + 96 * src1[5] + 42 * src1[6] + -7 * src1[7];
    tmp[6] = -1 * src1[4] + -2 * src1[5] + 96 * src1[6] + 42 * src1[7] + -7 * src1[8];
    tmp[7] = -1 * src1[5] + -2 * src1[6] + 96 * src1[7] + 42 * src1[8] + -7 * src1[9];
    
    tmp[8] = -1 * src1[srcStride - 2] + -2 * src1[srcStride - 1] + 96 * src1[srcStride + 0] + 42 * src1[srcStride + 1] + -7 * src1[srcStride + 2];
    tmp[9] = -1 * src1[srcStride - 1] + -2 * src1[srcStride + 0] + 96 * src1[srcStride + 1] + 42 * src1[srcStride + 2] + -7 * src1[srcStride + 3];
    tmp[10] = -1 * src1[srcStride + 0] + -2 * src1[srcStride + 1] + 96 * src1[srcStride + 2] + 42 * src1[srcStride + 3] + -7 * src1[srcStride + 4];
    tmp[11] = -1 * src1[srcStride + 1] + -2 * src1[srcStride + 2] + 96 * src1[srcStride + 3] + 42 * src1[srcStride + 4] + -7 * src1[srcStride + 5];
    tmp[12] = -1 * src1[srcStride + 2] + -2 * src1[srcStride + 3] + 96 * src1[srcStride + 4] + 42 * src1[srcStride + 5] + -7 * src1[srcStride + 6];
    tmp[13] = -1 * src1[srcStride + 3] + -2 * src1[srcStride + 4] + 96 * src1[srcStride + 5] + 42 * src1[srcStride + 6] + -7 * src1[srcStride + 7];
    tmp[14] = -1 * src1[srcStride + 4] + -2 * src1[srcStride + 5] + 96 * src1[srcStride + 6] + 42 * src1[srcStride + 7] + -7 * src1[srcStride + 8];
    tmp[15] = -1 * src1[srcStride + 5] + -2 * src1[srcStride + 6] + 96 * src1[srcStride + 7] + 42 * src1[srcStride + 8] + -7 * src1[srcStride + 9];

    tmp += 16;
    src1 += 2 * srcStride;
}
}
