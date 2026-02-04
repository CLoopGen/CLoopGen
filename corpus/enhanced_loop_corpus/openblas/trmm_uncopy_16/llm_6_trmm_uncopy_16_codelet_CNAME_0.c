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
    for (ii = 0; ii < 32; ii++) {
        b[0] = *(a01 + 0) + *(a01 + 1);
        b[1] = *(a02 + 0) + *(a02 + 1);
        b[2] = *(a03 + 0) + *(a03 + 1);
        b[3] = *(a04 + 0) + *(a04 + 1);
        b[4] = *(a05 + 0) + *(a05 + 1);
        b[5] = *(a06 + 0) + *(a06 + 1);
        b[6] = *(a07 + 0) + *(a07 + 1);
        b[7] = *(a08 + 0) + *(a08 + 1);
        b[8] = *(a09 + 0) + *(a09 + 1);
        b[9] = *(a10 + 0) + *(a10 + 1);
        b[10] = *(a11 + 0) + *(a11 + 1);
        b[11] = *(a12 + 0) + *(a12 + 1);
        b[12] = *(a13 + 0) + *(a13 + 1);
        b[13] = *(a14 + 0) + *(a14 + 1);
        b[14] = *(a15 + 0) + *(a15 + 1);
        b[15] = *(a16 + 0) + *(a16 + 1);
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
        b += 16;
    }
}
