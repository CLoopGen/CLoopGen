#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG row;
extern BLASLONG col;
extern BLASLONG i;
extern BLASLONG ii;
extern float *src0;
extern float *src1;
extern float *dest0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < col / 8; i += 1) {
    for (BLASLONG j = 0; j < 16; j += 8) {
        dest0[0 + j] = src0[0 + j];
        dest0[1 + j] = src0[1 + j];
        dest0[2 + j] = src0[2 + j];
        dest0[3 + j] = src0[3 + j];
        dest0[4 + j] = src0[4 + j];
        dest0[5 + j] = src0[5 + j];
        dest0[6 + j] = src0[6 + j];
        dest0[7 + j] = src0[7 + j];
    }
    for (BLASLONG j = 0; j < 16; j += 8) {
        dest0[16 + j] = src1[0 + j];
        dest0[17 + j] = src1[1 + j];
        dest0[18 + j] = src1[2 + j];
        dest0[19 + j] = src1[3 + j];
        dest0[20 + j] = src1[4 + j];
        dest0[21 + j] = src1[5 + j];
        dest0[22 + j] = src1[6 + j];
        dest0[23 + j] = src1[7 + j];
    }
    src0 = src0 + 16;
    src1 = src1 + 16;
    ii = (row << 4);
    dest0 = dest0 + ii;
}
}
