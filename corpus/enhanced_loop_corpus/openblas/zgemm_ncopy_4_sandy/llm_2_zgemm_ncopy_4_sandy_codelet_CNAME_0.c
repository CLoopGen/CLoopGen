#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG row;
extern BLASLONG col;
extern float *src;
extern BLASLONG srcdim;
extern float *dest;
extern BLASLONG i;
extern BLASLONG j;
extern BLASLONG ii;
extern float *src0;
extern float *src1;
extern float *src2;
extern float *src3;
extern float *dest0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < col / 4; j += 1) {
    src0 = src;
    src1 = src0 + 2 * srcdim;
    src2 = src1 + 2 * srcdim;
    src3 = src2 + 2 * srcdim;
    src = src3 + 2 * srcdim;
    dest0 = dest;
    ii = (row << 3);
    dest = dest + ii;

    // Reduced loop nesting: merge inner loop logic directly with stride handling
    for (i = 0; i < row / 4; i += 1) {
        BLASLONG offset = i * 32; // Each iteration writes 32 elements
        float* d = dest0 + offset;

        d[0]  = src0[0];  d[1]  = src0[1];
        d[2]  = src1[0];  d[3]  = src1[1];
        d[4]  = src2[0];  d[5]  = src2[1];
        d[6]  = src3[0];  d[7]  = src3[1];
        d[8]  = src0[2];  d[9]  = src0[3];
        d[10] = src1[2];  d[11] = src1[3];
        d[12] = src2[2];  d[13] = src2[3];
        d[14] = src3[2];  d[15] = src3[3];
        d[16] = src0[4];  d[17] = src0[5];
        d[18] = src1[4];  d[19] = src1[5];
        d[20] = src2[4];  d[21] = src2[5];
        d[22] = src3[4];  d[23] = src3[5];
        d[24] = src0[6];  d[25] = src0[7];
        d[26] = src1[6];  d[27] = src1[7];
        d[28] = src2[6];  d[29] = src2[7];
        d[30] = src3[6];  d[31] = src3[7];

        src0 += 8;
        src1 += 8;
        src2 += 8;
        src3 += 8;
    }

    // Handle remaining rows using direct unrolled conditions (same as original)
    if (row & 2) {
        dest0 += (row / 4) * 32; // Adjust dest0 to current write position
        dest0[0] = src0[0];  dest0[1] = src0[1];
        dest0[2] = src1[0];  dest0[3] = src1[1];
        dest0[4] = src2[0];  dest0[5] = src2[1];
        dest0[6] = src3[0];  dest0[7] = src3[1];
        dest0[8] = src0[2];  dest0[9] = src0[3];
        dest0[10] = src1[2]; dest0[11] = src1[3];
        dest0[12] = src2[2]; dest0[13] = src2[3];
        dest0[14] = src3[2]; dest0[15] = src3[3];
        src0 += 4; src1 += 4; src2 += 4; src3 += 4;
        dest0 += 16;
    }
    if (row & 1) {
        dest0[0] = src0[0];  dest0[1] = src0[1];
        dest0[2] = src1[0];  dest0[3] = src1[1];
        dest0[4] = src2[0];  dest0[5] = src2[1];
        dest0[6] = src3[0];  dest0[7] = src3[1];
        src0 += 2; src1 += 2; src2 += 2; src3 += 2;
        dest0 += 8;
    }
}
}
