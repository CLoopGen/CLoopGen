#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;
extern float *a05;
extern float *a06;
extern float *a07;
extern float *a08;
extern float *a09;
extern float *a10;
extern float *a11;
extern float *a12;
extern float *a13;
extern float *a14;
extern float *a15;
extern float *a16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 64; ii += 4) {
    b[0]  = *(a01 + 0); b[1]  = *(a02 + 0);
    b[2]  = *(a03 + 0); b[3]  = *(a04 + 0);
    b[4]  = *(a05 + 0); b[5]  = *(a06 + 0);
    b[6]  = *(a07 + 0); b[7]  = *(a08 + 0);
    b[8]  = *(a09 + 0); b[9]  = *(a10 + 0);
    b[10] = *(a11 + 0); b[11] = *(a12 + 0);
    b[12] = *(a13 + 0); b[13] = *(a14 + 0);
    b[14] = *(a15 + 0); b[15] = *(a16 + 0);

    b[16] = *(a01 + 1); b[17] = *(a02 + 1);
    b[18] = *(a03 + 1); b[19] = *(a04 + 1);
    b[20] = *(a05 + 1); b[21] = *(a06 + 1);
    b[22] = *(a07 + 1); b[23] = *(a08 + 1);
    b[24] = *(a09 + 1); b[25] = *(a10 + 1);
    b[26] = *(a11 + 1); b[27] = *(a12 + 1);
    b[28] = *(a13 + 1); b[29] = *(a14 + 1);
    b[30] = *(a15 + 1); b[31] = *(a16 + 1);

    b[32] = *(a01 + 2); b[33] = *(a02 + 2);
    b[34] = *(a03 + 2); b[35] = *(a04 + 2);
    b[36] = *(a05 + 2); b[37] = *(a06 + 2);
    b[38] = *(a07 + 2); b[39] = *(a08 + 2);
    b[40] = *(a09 + 2); b[41] = *(a10 + 2);
    b[42] = *(a11 + 2); b[43] = *(a12 + 2);
    b[44] = *(a13 + 2); b[45] = *(a14 + 2);
    b[46] = *(a15 + 2); b[47] = *(a16 + 2);

    b[48] = *(a01 + 3); b[49] = *(a02 + 3);
    b[50] = *(a03 + 3); b[51] = *(a04 + 3);
    b[52] = *(a05 + 3); b[53] = *(a06 + 3);
    b[54] = *(a07 + 3); b[55] = *(a08 + 3);
    b[56] = *(a09 + 3); b[57] = *(a10 + 3);
    b[58] = *(a11 + 3); b[59] = *(a12 + 3);
    b[60] = *(a13 + 3); b[61] = *(a14 + 3);
    b[62] = *(a15 + 3); b[63] = *(a16 + 3);

    a01 += 4; a02 += 4; a03 += 4; a04 += 4;
    a05 += 4; a06 += 4; a07 += 4; a08 += 4;
    a09 += 4; a10 += 4; a11 += 4; a12 += 4;
    a13 += 4; a14 += 4; a15 += 4; a16 += 4;

    b += 64;
}
}
