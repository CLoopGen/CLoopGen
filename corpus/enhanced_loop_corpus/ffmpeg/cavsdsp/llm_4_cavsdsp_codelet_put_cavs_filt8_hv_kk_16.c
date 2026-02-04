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
    if (i >= 1) {
        tmp[0] = -7 * src1[-1] + 42 * src1[0] + 96 * src1[1] + -2 * src1[2] + -1 * src1[3];
        tmp[1] = -7 * src1[0] + 42 * src1[1] + 96 * src1[2] + -2 * src1[3] + -1 * src1[4];
        tmp[2] = -7 * src1[1] + 42 * src1[2] + 96 * src1[3] + -2 * src1[4] + -1 * src1[5];
        tmp[3] = -7 * src1[2] + 42 * src1[3] + 96 * src1[4] + -2 * src1[5] + -1 * src1[6];
        tmp[4] = -7 * src1[3] + 42 * src1[4] + 96 * src1[5] + -2 * src1[6] + -1 * src1[7];
        tmp[5] = -7 * src1[4] + 42 * src1[5] + 96 * src1[6] + -2 * src1[7] + -1 * src1[8];
        tmp[6] = -7 * src1[5] + 42 * src1[6] + 96 * src1[7] + -2 * src1[8] + -1 * src1[9];
        tmp[7] = -7 * src1[6] + 42 * src1[7] + 96 * src1[8] + -2 * src1[9] + -1 * src1[10];
    } else {
        tmp[0] = tmp[1] = tmp[2] = tmp[3] = tmp[4] = tmp[5] = tmp[6] = tmp[7] = 0;
    }
    tmp += 8;
    src1 += srcStride;
}
}
