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
    int16_t t0 = 0 * src1[-2] + -7 * src1[-1] + 42 * src1[0] + 96 * src1[1] + -2 * src1[2] + -1 * src1[3];
    int16_t t1 = 0 * src1[-1] + -7 * src1[0] + 42 * src1[1] + 96 * src1[2] + -2 * src1[3] + -1 * src1[4];
    int16_t t2 = 0 * src1[0] + -7 * src1[1] + 42 * src1[2] + 96 * src1[3] + -2 * src1[4] + -1 * src1[5];
    int16_t t3 = 0 * src1[1] + -7 * src1[2] + 42 * src1[3] + 96 * src1[4] + -2 * src1[5] + -1 * src1[6];
    int16_t t4 = 0 * src1[2] + -7 * src1[3] + 42 * src1[4] + 96 * src1[5] + -2 * src1[6] + -1 * src1[7];
    int16_t t5 = 0 * src1[3] + -7 * src1[4] + 42 * src1[5] + 96 * src1[6] + -2 * src1[7] + -1 * src1[8];
    int16_t t6 = 0 * src1[4] + -7 * src1[5] + 42 * src1[6] + 96 * src1[7] + -2 * src1[8] + -1 * src1[9];
    int16_t t7 = 0 * src1[5] + -7 * src1[6] + 42 * src1[7] + 96 * src1[8] + -2 * src1[9] + -1 * src1[10];

    tmp[0] = t0;
    tmp[1] = t1;
    tmp[2] = t2;
    tmp[3] = t3;
    tmp[4] = t4;
    tmp[5] = t5;
    tmp[6] = t6;
    tmp[7] = t7;

    tmp += 8;
    src1 += srcStride;
}
}
