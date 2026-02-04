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
for (i = 0; i < col / 4; i += 1) {
    if (i % 2 == 0) {
        dest0[0] = src0[0];
        dest0[1] = src0[1];
        dest0[2] = src0[2];
        dest0[3] = src0[3];
        dest0[4] = src0[4];
        dest0[5] = src0[5];
        dest0[6] = src0[6];
        dest0[7] = src0[7];
        dest0[8] = src1[0];
        dest0[9] = src1[1];
        dest0[10] = src1[2];
        dest0[11] = src1[3];
        dest0[12] = src1[4];
        dest0[13] = src1[5];
        dest0[14] = src1[6];
        dest0[15] = src1[7];
    } else {
        for (int j = 0; j < 8; j++) {
            dest0[j]     = src0[j];
            dest0[j + 8] = src1[j];
        }
    }
    src0 = src0 + 8;
    src1 = src1 + 8;
    ii = (row << 3);
    dest0 = dest0 + ii;
}
}
