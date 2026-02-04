#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG row;
extern BLASLONG i;
extern BLASLONG ii;
extern float *src0;
extern float *src1;
extern float *dest0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < row / 8; i += 1) {
    dest0[0] = src0[0];
    dest0[1] = src0[1];
    dest0[2] = src1[0];
    dest0[3] = src1[1];
    dest0[4] = src0[2];
    dest0[5] = src0[3];
    dest0[6] = src1[2];
    dest0[7] = src1[3];
    src0 = src0 + 4;
    src1 = src1 + 4;
    ii = (2 << 2);
    dest0 = dest0 + ii;
}
}
