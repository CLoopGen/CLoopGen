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
extern float *src4;
extern float *src5;
extern float *src6;
extern float *src7;
extern float *dest0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < col / 16; j += 1) {
    src0 = src;
    src1 = src0 + 2 * srcdim;
    src2 = src1 + 2 * srcdim;
    src3 = src2 + 2 * srcdim;
    src4 = src3 + 2 * srcdim;
    src5 = src4 + 2 * srcdim;
    src6 = src5 + 2 * srcdim;
    src7 = src6 + 2 * srcdim;
    src = src7 + 2 * srcdim;
    dest0 = dest;
    ii = (row << 5);
    dest = dest + ii;
    for (i = 0; i < row / 8; i += 1) {
        dest0[0] = src0[0]; dest0[1] = src0[1]; dest0[2] = src0[2]; dest0[3] = src0[3];
        dest0[4] = src0[4]; dest0[5] = src0[5]; dest0[6] = src0[6]; dest0[7] = src0[7];
        dest0[8] = src1[0]; dest0[9] = src1[1]; dest0[10] = src1[2]; dest0[11] = src1[3];
        dest0[12] = src1[4]; dest0[13] = src1[5]; dest0[14] = src1[6]; dest0[15] = src1[7];
        dest0[16] = src2[0]; dest0[17] = src2[1]; dest0[18] = src2[2]; dest0[19] = src2[3];
        dest0[20] = src2[4]; dest0[21] = src2[5]; dest0[22] = src2[6]; dest0[23] = src2[7];
        dest0[24] = src3[0]; dest0[25] = src3[1]; dest0[26] = src3[2]; dest0[27] = src3[3];
        dest0[28] = src3[4]; dest0[29] = src3[5]; dest0[30] = src3[6]; dest0[31] = src3[7];
        dest0[32] = src4[0]; dest0[33] = src4[1]; dest0[34] = src4[2]; dest0[35] = src4[3];
        dest0[36] = src4[4]; dest0[37] = src4[5]; dest0[38] = src4[6]; dest0[39] = src4[7];
        dest0[40] = src5[0]; dest0[41] = src5[1]; dest0[42] = src5[2]; dest0[43] = src5[3];
        dest0[44] = src5[4]; dest0[45] = src5[5]; dest0[46] = src5[6]; dest0[47] = src5[7];
        dest0[48] = src6[0]; dest0[49] = src6[1]; dest0[50] = src6[2]; dest0[51] = src6[3];
        dest0[52] = src6[4]; dest0[53] = src6[5]; dest0[54] = src6[6]; dest0[55] = src6[7];
        dest0[56] = src7[0]; dest0[57] = src7[1]; dest0[58] = src7[2]; dest0[59] = src7[3];
        dest0[60] = src7[4]; dest0[61] = src7[5]; dest0[62] = src7[6]; dest0[63] = src7[7];

        src0 += 16; src1 += 16; src2 += 16; src3 += 16;
        src4 += 16; src5 += 16; src6 += 16; src7 += 16;
        dest0 += 64;
    }
    if (row & 4) {
        dest0[0] = src0[0]; dest0[1] = src0[1]; dest0[2] = src0[2]; dest0[3] = src0[3];
        dest0[4] = src0[4]; dest0[5] = src0[5]; dest0[6] = src0[6]; dest0[7] = src0[7];
        dest0[8] = src1[0]; dest0[9] = src1[1]; dest0[10] = src1[2]; dest0[11] = src1[3];
        dest0[12] = src1[4]; dest0[13] = src1[5]; dest0[14] = src1[6]; dest0[15] = src1[7];
        dest0[16] = src2[0]; dest0[17] = src2[1]; dest0[18] = src2[2]; dest0[19] = src2[3];
        dest0[20] = src2[4]; dest0[21] = src2[5]; dest0[22] = src2[6]; dest0[23] = src2[7];
        dest0[24] = src3[0]; dest0[25] = src3[1]; dest0[26] = src3[2]; dest0[27] = src3[3];
        dest0[28] = src3[4]; dest0[29] = src3[5]; dest0[30] = src3[6]; dest0[31] = src3[7];
        dest0[32] = src4[0]; dest0[33] = src4[1]; dest0[34] = src4[2]; dest0[35] = src4[3];
        dest0[36] = src4[4]; dest0[37] = src4[5]; dest0[38] = src4[6]; dest0[39] = src4[7];
        dest0[40] = src5[0]; dest0[41] = src5[1]; dest0[42] = src5[2]; dest0[43] = src5[3];
        dest0[44] = src5[4]; dest0[45] = src5[5]; dest0[46] = src5[6]; dest0[47] = src5[7];
        dest0[48] = src6[0]; dest0[49] = src6[1]; dest0[50] = src6[2]; dest0[51] = src6[3];
        dest0[52] = src6[4]; dest0[53] = src6[5]; dest0[54] = src6[6]; dest0[55] = src6[7];
        dest0[56] = src7[0]; dest0[57] = src7[1]; dest0[58] = src7[2]; dest0[59] = src7[3];
        dest0[60] = src7[4]; dest0[61] = src7[5]; dest0[62] = src7[6]; dest0[63] = src7[7];

        src0 += 8; src1 += 8; src2 += 8; src3 += 8;
        src4 += 8; src5 += 8; src6 += 8; src7 += 8;
        dest0 += 64;
    }
    if (row & 2) {
        dest0[0] = src0[0]; dest0[1] = src0[1]; dest0[2] = src1[0]; dest0[3] = src1[1];
        dest0[4] = src2[0]; dest0[5] = src2[1]; dest0[6] = src3[0]; dest0[7] = src3[1];
        dest0[8] = src4[0]; dest0[9] = src4[1]; dest0[10] = src5[0]; dest0[11] = src5[1];
        dest0[12] = src6[0]; dest0[13] = src6[1]; dest0[14] = src7[0]; dest0[15] = src7[1];
        dest0[16] = src0[2]; dest0[17] = src0[3]; dest0[18] = src1[2]; dest0[19] = src1[3];
        dest0[20] = src2[2]; dest0[21] = src2[3]; dest0[22] = src3[2]; dest0[23] = src3[3];
        dest0[24] = src4[2]; dest0[25] = src4[3]; dest0[26] = src5[2]; dest0[27] = src5[3];
        dest0[28] = src6[2]; dest0[29] = src6[3]; dest0[30] = src7[2]; dest0[31] = src7[3];

        src0 += 4; src1 += 4; src2 += 4; src3 += 4;
        src4 += 4; src5 += 4; src6 += 4; src7 += 4;
        dest0 += 32;
    }
    if (row & 1) {
        dest0[0] = src0[0]; dest0[1] = src0[1]; dest0[2] = src1[0]; dest0[3] = src1[1];
        dest0[4] = src2[0]; dest0[5] = src2[1]; dest0[6] = src3[0]; dest0[7] = src3[1];
        dest0[8] = src4[0]; dest0[9] = src4[1]; dest0[10] = src5[0]; dest0[11] = src5[1];
        dest0[12] = src6[0]; dest0[13] = src6[1]; dest0[14] = src7[0]; dest0[15] = src7[1];

        src0 += 2; src1 += 2; src2 += 2; src3 += 2;
        src4 += 2; src5 += 2; src6 += 2; src7 += 2;
        dest0 += 16;
    }
}
}
