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
    int offset1 = 0, offset2 = srcStride;
    tmp[0] = -7 * src1[offset1-1] + 42 * src1[offset1+0] + 96 * src1[offset1+1] - 2 * src1[offset1+2] - src1[offset1+3];
    tmp[1] = -7 * src1[offset1+0] + 42 * src1[offset1+1] + 96 * src1[offset1+2] - 2 * src1[offset1+3] - src1[offset1+4];
    tmp[2] = -7 * src1[offset1+1] + 42 * src1[offset1+2] + 96 * src1[offset1+3] - 2 * src1[offset1+4] - src1[offset1+5];
    tmp[3] = -7 * src1[offset1+2] + 42 * src1[offset1+3] + 96 * src1[offset1+4] - 2 * src1[offset1+5] - src1[offset1+6];

    tmp[4] = -7 * src1[offset2-1] + 42 * src1[offset2+0] + 96 * src1[offset2+1] - 2 * src1[offset2+2] - src1[offset2+3];
    tmp[5] = -7 * src1[offset2+0] + 42 * src1[offset2+1] + 96 * src1[offset2+2] - 2 * src1[offset2+3] - src1[offset2+4];
    tmp[6] = -7 * src1[offset2+1] + 42 * src1[offset2+2] + 96 * src1[offset2+3] - 2 * src1[offset2+4] - src1[offset2+5];
    tmp[7] = -7 * src1[offset2+2] + 42 * src1[offset2+3] + 96 * src1[offset2+4] - 2 * src1[offset2+5] - src1[offset2+6];

    tmp += 8;
    src1 += 2 * srcStride;
}
}
