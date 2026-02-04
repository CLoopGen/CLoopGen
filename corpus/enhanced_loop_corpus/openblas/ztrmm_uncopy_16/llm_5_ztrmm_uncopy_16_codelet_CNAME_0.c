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
    float *b_local = b;
    for (ii = 0; ii < 16; ii++) {
        b_local[0] = *(a01 + 0);
        b_local[1] = *(a01 + 1);
        b_local[2] = *(a02 + 0);
        b_local[3] = *(a02 + 1);
        b_local[4] = *(a03 + 0);
        b_local[5] = *(a03 + 1);
        b_local[6] = *(a04 + 0);
        b_local[7] = *(a04 + 1);
        b_local[8] = *(a05 + 0);
        b_local[9] = *(a05 + 1);
        b_local[10] = *(a06 + 0);
        b_local[11] = *(a06 + 1);
        b_local[12] = *(a07 + 0);
        b_local[13] = *(a07 + 1);
        b_local[14] = *(a08 + 0);
        b_local[15] = *(a08 + 1);
        b_local[16] = *(a09 + 0);
        b_local[17] = *(a09 + 1);
        b_local[18] = *(a10 + 0);
        b_local[19] = *(a10 + 1);
        b_local[20] = *(a11 + 0);
        b_local[21] = *(a11 + 1);
        b_local[22] = *(a12 + 0);
        b_local[23] = *(a12 + 1);
        b_local[24] = *(a13 + 0);
        b_local[25] = *(a13 + 1);
        b_local[26] = *(a14 + 0);
        b_local[27] = *(a14 + 1);
        b_local[28] = *(a15 + 0);
        b_local[29] = *(a15 + 1);
        b_local[30] = *(a16 + 0);
        b_local[31] = *(a16 + 1);

        a01 += 2;
        a02 += 2;
        a03 += 2;
        a04 += 2;
        a05 += 2;
        a06 += 2;
        a07 += 2;
        a08 += 2;
        a09 += 2;
        a10 += 2;
        a11 += 2;
        a12 += 2;
        a13 += 2;
        a14 += 2;
        a15 += 2;
        a16 += 2;
        b_local += 32;
    }
    b = b_local;
}
