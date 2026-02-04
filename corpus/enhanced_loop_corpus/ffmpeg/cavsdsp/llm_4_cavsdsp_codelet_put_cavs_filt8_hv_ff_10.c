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
for (i = 0; i < h + 5; i++) {
    if (i % 2 == 0) {
        tmp[0] = -1 * src1[-1] + 5 * src1[0] + 5 * src1[1] + -1 * src1[2];
        tmp[1] = -1 * src1[0] + 5 * src1[1] + 5 * src1[2] + -1 * src1[3];
        tmp[2] = -1 * src1[1] + 5 * src1[2] + 5 * src1[3] + -1 * src1[4];
        tmp[3] = -1 * src1[2] + 5 * src1[3] + 5 * src1[4] + -1 * src1[5];
        tmp[4] = -1 * src1[3] + 5 * src1[4] + 5 * src1[5] + -1 * src1[6];
        tmp[5] = -1 * src1[4] + 5 * src1[5] + 5 * src1[6] + -1 * src1[7];
        tmp[6] = -1 * src1[5] + 5 * src1[6] + 5 * src1[7] + -1 * src1[8];
        tmp[7] = -1 * src1[6] + 5 * src1[7] + 5 * src1[8] + -1 * src1[9];
    } else {
        tmp[0] = 5 * src1[0] + 5 * src1[1];
        tmp[1] = 5 * src1[1] + 5 * src1[2];
        tmp[2] = 5 * src1[2] + 5 * src1[3];
        tmp[3] = 5 * src1[3] + 5 * src1[4];
        tmp[4] = 5 * src1[4] + 5 * src1[5];
        tmp[5] = 5 * src1[5] + 5 * src1[6];
        tmp[6] = 5 * src1[6] + 5 * src1[7];
        tmp[7] = 5 * src1[7] + 5 * src1[8];
    }
    tmp += 8;
    src1 += srcStride;
}
}
