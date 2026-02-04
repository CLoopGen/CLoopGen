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
    int offset1 = 0, offset2 = 8;
    tmp[offset1 + 0] = 0*src1[-2] + -1*src1[-1] + 5*src1[0] + 5*src1[1] + -1*src1[2] + 0*src1[3];
    tmp[offset1 + 1] = 0*src1[-1] + -1*src1[0] + 5*src1[1] + 5*src1[2] + -1*src1[3] + 0*src1[4];
    tmp[offset1 + 2] = 0*src1[0] + -1*src1[1] + 5*src1[2] + 5*src1[3] + -1*src1[4] + 0*src1[5];
    tmp[offset1 + 3] = 0*src1[1] + -1*src1[2] + 5*src1[3] + 5*src1[4] + -1*src1[5] + 0*src1[6];
    tmp[offset1 + 4] = 0*src1[2] + -1*src1[3] + 5*src1[4] + 5*src1[5] + -1*src1[6] + 0*src1[7];
    tmp[offset1 + 5] = 0*src1[3] + -1*src1[4] + 5*src1[5] + 5*src1[6] + -1*src1[7] + 0*src1[8];
    tmp[offset1 + 6] = 0*src1[4] + -1*src1[5] + 5*src1[6] + 5*src1[7] + -1*src1[8] + 0*src1[9];
    tmp[offset1 + 7] = 0*src1[5] + -1*src1[6] + 5*src1[7] + 5*src1[8] + -1*src1[9] + 0*src1[10];

    src1 += srcStride;
    
    if (i + 1 < h + 8) {
        tmp[offset2 + 0] = 0*src1[-2] + -1*src1[-1] + 5*src1[0] + 5*src1[1] + -1*src1[2] + 0*src1[3];
        tmp[offset2 + 1] = 0*src1[-1] + -1*src1[0] + 5*src1[1] + 5*src1[2] + -1*src1[3] + 0*src1[4];
        tmp[offset2 + 2] = 0*src1[0] + -1*src1[1] + 5*src1[2] + 5*src1[3] + -1*src1[4] + 0*src1[5];
        tmp[offset2 + 3] = 0*src1[1] + -1*src1[2] + 5*src1[3] + 5*src1[4] + -1*src1[5] + 0*src1[6];
        tmp[offset2 + 4] = 0*src1[2] + -1*src1[3] + 5*src1[4] + 5*src1[5] + -1*src1[6] + 0*src1[7];
        tmp[offset2 + 5] = 0*src1[3] + -1*src1[4] + 5*src1[5] + 5*src1[6] + -1*src1[7] + 0*src1[8];
        tmp[offset2 + 6] = 0*src1[4] + -1*src1[5] + 5*src1[6] + 5*src1[7] + -1*src1[8] + 0*src1[9];
        tmp[offset2 + 7] = 0*src1[5] + -1*src1[6] + 5*src1[7] + 5*src1[8] + -1*src1[9] + 0*src1[10];
        src1 += srcStride;
        tmp += 16;
    } else {
        tmp += 8;
    }
}
}
