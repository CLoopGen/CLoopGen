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
    for (BLASLONG j = 0; j < row; j++) {
        dest0[0] = src0[0];
        dest0[1] = src0[1];
        dest0[2] = src0[2];
        dest0[3] = src0[3];
        dest0[4] = src0[4];
        dest0[5] = src0[5];
        dest0[6] = src0[6];
        dest0[7] = src0[7];
        dest0[8] = src0[8];
        dest0[9] = src0[9];
        dest0[10] = src0[10];
        dest0[11] = src0[11];
        dest0[12] = src0[12];
        dest0[13] = src0[13];
        dest0[14] = src0[14];
        dest0[15] = src0[15];
        src0 = src0 + 16;
        dest0 = dest0 + 16;
    }
}
}
