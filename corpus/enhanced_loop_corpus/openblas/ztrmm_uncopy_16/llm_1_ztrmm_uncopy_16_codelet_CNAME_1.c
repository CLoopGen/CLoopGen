#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
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
    for (ii = 0; ii < i; ii++) {
        for (BLASLONG k = 0; k < 2; k++) {
            b[k +  0] = *(a01 + k);
            b[k +  2] = *(a02 + k);
            b[k +  4] = *(a03 + k);
            b[k +  6] = *(a04 + k);
            b[k +  8] = *(a05 + k);
            b[k + 10] = *(a06 + k);
            b[k + 12] = *(a07 + k);
            b[k + 14] = *(a08 + k);
            b[k + 16] = *(a09 + k);
            b[k + 18] = *(a10 + k);
            b[k + 20] = *(a11 + k);
            b[k + 22] = *(a12 + k);
            b[k + 24] = *(a13 + k);
            b[k + 26] = *(a14 + k);
            b[k + 28] = *(a15 + k);
            b[k + 30] = *(a16 + k);
        }
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
        b += 32;
    }
}
