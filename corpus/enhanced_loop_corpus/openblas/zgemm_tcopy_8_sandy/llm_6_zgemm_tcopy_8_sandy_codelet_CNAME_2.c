#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG row;
extern BLASLONG col;
extern BLASLONG i;
extern BLASLONG ii;
extern float *src0;
extern float *dest0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < col / 8; i += 1) {
    float temp0 = src0[0], temp1 = src0[1], temp2 = src0[2], temp3 = src0[3];
    float temp4 = src0[4], temp5 = src0[5], temp6 = src0[6], temp7 = src0[7];
    float temp8 = src0[8], temp9 = src0[9], temp10 = src0[10], temp11 = src0[11];
    float temp12 = src0[12], temp13 = src0[13], temp14 = src0[14], temp15 = src0[15];

    dest0[0] = temp0;
    dest0[1] = temp1;
    dest0[2] = temp2;
    dest0[3] = temp3;
    dest0[4] = temp4;
    dest0[5] = temp5;
    dest0[6] = temp6;
    dest0[7] = temp7;
    dest0[8] = temp8;
    dest0[9] = temp9;
    dest0[10] = temp10;
    dest0[11] = temp11;
    dest0[12] = temp12;
    dest0[13] = temp13;
    dest0[14] = temp14;
    dest0[15] = temp15;

    src0 = src0 + 16;
    ii = (row << 4);
    dest0 = dest0 + ii;
}
}
