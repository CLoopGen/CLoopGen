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
    int j;
    for (j = 0; j < 2 && (i + j) < h + 8; j++) {
        tmp[0] = -1 * src1[-2] + -2 * src1[-1] + 96 * src1[0] + 42 * src1[1] + -7 * src1[2] + 0 * src1[3];
        tmp[1] = -1 * src1[-1] + -2 * src1[0] + 96 * src1[1] + 42 * src1[2] + -7 * src1[3] + 0 * src1[4];
        tmp[2] = -1 * src1[0] + -2 * src1[1] + 96 * src1[2] + 42 * src1[3] + -7 * src1[4] + 0 * src1[5];
        tmp[3] = -1 * src1[1] + -2 * src1[2] + 96 * src1[3] + 42 * src1[4] + -7 * src1[5] + 0 * src1[6];
        tmp[4] = -1 * src1[2] + -2 * src1[3] + 96 * src1[4] + 42 * src1[5] + -7 * src1[6] + 0 * src1[7];
        tmp[5] = -1 * src1[3] + -2 * src1[4] + 96 * src1[5] + 42 * src1[6] + -7 * src1[7] + 0 * src1[8];
        tmp[6] = -1 * src1[4] + -2 * src1[5] + 96 * src1[6] + 42 * src1[7] + -7 * src1[8] + 0 * src1[9];
        tmp[7] = -1 * src1[5] + -2 * src1[6] + 96 * src1[7] + 42 * src1[8] + -7 * src1[9] + 0 * src1[10];
        tmp += 8;
        src1 += srcStride;
    }
}
}
