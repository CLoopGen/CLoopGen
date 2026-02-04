#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG row;
extern BLASLONG i;
extern BLASLONG ii;
extern float *src0;
extern float *src1;
extern float *src2;
extern float *src3;
extern float *dest0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < row / 8; i += 1) {
    dest0[0] = src0[0];
    dest0[1] = src0[1];
    dest0[2] = src1[0];
    dest0[3] = src1[1];
    dest0[4] = src2[0];
    dest0[5] = src2[1];
    dest0[6] = src3[0];
    dest0[7] = src3[1];
    dest0[8] = src0[2];
    dest0[9] = src0[3];
    dest0[10] = src1[2];
    dest0[11] = src1[3];
    dest0[12] = src2[2];
    dest0[13] = src2[3];
    dest0[14] = src3[2];
    dest0[15] = src3[3];
    src0 = src0 + 4;
    src1 = src1 + 4;
    src2 = src2 + 4;
    src3 = src3 + 4;
    ii = (4 << 2);
    dest0 = dest0 + ii;
}
}
