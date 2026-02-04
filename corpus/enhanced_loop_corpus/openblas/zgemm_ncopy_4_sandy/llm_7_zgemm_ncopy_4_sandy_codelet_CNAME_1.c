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
BLASLONG temp_src0[8], temp_src1[8];
for (i = 0; i < row / 4; i += 1) {
    for (BLASLONG j = 0; j < 8; j++) {
        temp_src0[j] = src0[j];
        temp_src1[j] = src1[j];
    }
    dest0[0] = temp_src0[0];
    dest0[1] = temp_src0[1];
    dest0[2] = temp_src1[0];
    dest0[3] = temp_src1[1];
    dest0[4] = temp_src0[2];
    dest0[5] = temp_src0[3];
    dest0[6] = temp_src1[2];
    dest0[7] = temp_src1[3];
    dest0[8] = temp_src0[4];
    dest0[9] = temp_src0[5];
    dest0[10] = temp_src1[4];
    dest0[11] = temp_src1[5];
    dest0[12] = temp_src0[6];
    dest0[13] = temp_src0[7];
    dest0[14] = temp_src1[6];
    dest0[15] = temp_src1[7];
    src0 += 8;
    src1 += 8;
    ii = (4 << 2);
    dest0 += ii;
}
}
