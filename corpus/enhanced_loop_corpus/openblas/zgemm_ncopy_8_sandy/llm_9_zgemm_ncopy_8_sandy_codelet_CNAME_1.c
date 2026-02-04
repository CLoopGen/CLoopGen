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
for (i = 0; i < row / 2; i += 1) {
    dest0[0] = src0[0];
    dest0[1] = src0[1];
    dest0[2] = src0[2];
    dest0[3] = src0[3];
    dest0[4] = src1[0];
    dest0[5] = src1[1];
    dest0[6] = src1[2];
    dest0[7] = src1[3];
    dest0[8] = src2[0];
    dest0[9] = src2[1];
    dest0[10] = src2[2];
    dest0[11] = src2[3];
    dest0[12] = src3[0];
    dest0[13] = src3[1];
    dest0[14] = src3[2];
    dest0[15] = src3[3];

    dest0[16] = src0[4];
    dest0[17] = src0[5];
    dest0[18] = src0[6];
    dest0[19] = src0[7];
    dest0[20] = src1[4];
    dest0[21] = src1[5];
    dest0[22] = src1[6];
    dest0[23] = src1[7];
    dest0[24] = src2[4];
    dest0[25] = src2[5];
    dest0[26] = src2[6];
    dest0[27] = src2[7];
    dest0[28] = src3[4];
    dest0[29] = src3[5];
    dest0[30] = src3[6];
    dest0[31] = src3[7];

    dest0[32] = src0[8];
    dest0[33] = src0[9];
    dest0[34] = src0[10];
    dest0[35] = src0[11];
    dest0[36] = src1[8];
    dest0[37] = src1[9];
    dest0[38] = src1[10];
    dest0[39] = src1[11];
    dest0[40] = src2[8];
    dest0[41] = src2[9];
    dest0[42] = src2[10];
    dest0[43] = src2[11];
    dest0[44] = src3[8];
    dest0[45] = src3[9];
    dest0[46] = src3[10];
    dest0[47] = src3[11];

    dest0[48] = src0[12];
    dest0[49] = src0[13];
    dest0[50] = src0[14];
    dest0[51] = src0[15];
    dest0[52] = src1[12];
    dest0[53] = src1[13];
    dest0[54] = src1[14];
    dest0[55] = src1[15];
    dest0[56] = src2[12];
    dest0[57] = src2[13];
    dest0[58] = src2[14];
    dest0[59] = src2[15];
    dest0[60] = src3[12];
    dest0[61] = src3[13];
    dest0[62] = src3[14];
    dest0[63] = src3[15];

    src0 = src0 + 16;
    src1 = src1 + 16;
    src2 = src2 + 16;
    src3 = src3 + 16;
    ii = (4 << 4);
    dest0 = dest0 + ii;
}
}
