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
for (i = 0; i < row / 4; i += 2) {
    if (i + 1 < row / 4) {
        // Unroll two iterations into one
        // First iteration
        dest0[0] = src0[0];
        dest0[1] = src0[1];
        dest0[2] = src1[0];
        dest0[3] = src1[1];
        dest0[4] = src0[2];
        dest0[5] = src0[3];
        dest0[6] = src1[2];
        dest0[7] = src1[3];
        dest0[8] = src0[4];
        dest0[9] = src0[5];
        dest0[10] = src1[4];
        dest0[11] = src1[5];
        dest0[12] = src0[6];
        dest0[13] = src0[7];
        dest0[14] = src1[6];
        dest0[15] = src1[7];

        // Second iteration
        float *src0_2 = src0 + 8;
        float *src1_2 = src1 + 8;
        float *dest0_2 = dest0 + 16;

        dest0_2[0] = src0_2[0];
        dest0_2[1] = src0_2[1];
        dest0_2[2] = src1_2[0];
        dest0_2[3] = src1_2[1];
        dest0_2[4] = src0_2[2];
        dest0_2[5] = src0_2[3];
        dest0_2[6] = src1_2[2];
        dest0_2[7] = src1_2[3];
        dest0_2[8] = src0_2[4];
        dest0_2[9] = src0_2[5];
        dest0_2[10] = src1_2[4];
        dest0_2[11] = src1_2[5];
        dest0_2[12] = src0_2[6];
        dest0_2[13] = src0_2[7];
        dest0_2[14] = src1_2[6];
        dest0_2[15] = src1_2[7];

        src0 = src0_2 + 8;
        src1 = src1_2 + 8;
        dest0 = dest0_2 + 16;
    } else {
        // Final single iteration if odd number of iterations
        dest0[0] = src0[0];
        dest0[1] = src0[1];
        dest0[2] = src1[0];
        dest0[3] = src1[1];
        dest0[4] = src0[2];
        dest0[5] = src0[3];
        dest0[6] = src1[2];
        dest0[7] = src1[3];
        dest0[8] = src0[4];
        dest0[9] = src0[5];
        dest0[10] = src1[4];
        dest0[11] = src1[5];
        dest0[12] = src0[6];
        dest0[13] = src0[7];
        dest0[14] = src1[6];
        dest0[15] = src1[7];
        src0 += 8;
        src1 += 8;
        ii = (4 << 2);
        dest0 += ii;
    }
}
}
