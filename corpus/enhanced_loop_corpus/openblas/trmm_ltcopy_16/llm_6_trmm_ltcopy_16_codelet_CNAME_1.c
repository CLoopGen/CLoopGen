#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
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
    float temp0 = *(a01 + 0);
    float temp1 = *(a01 + 1);
    float temp2 = *(a01 + 2);
    float temp3 = *(a01 + 3);
    float temp4 = *(a01 + 4);
    float temp5 = *(a01 + 5);
    float temp6 = *(a01 + 6);
    float temp7 = *(a01 + 7);
    float temp8 = *(a01 + 8);
    float temp9 = *(a01 + 9);
    float temp10 = *(a01 + 10);
    float temp11 = *(a01 + 11);
    float temp12 = *(a01 + 12);
    float temp13 = *(a01 + 13);
    float temp14 = *(a01 + 14);
    float temp15 = *(a01 + 15);

    b[0] = temp0;
    b[1] = temp1;
    b[2] = temp2;
    b[3] = temp3;
    b[4] = temp4;
    b[5] = temp5;
    b[6] = temp6;
    b[7] = temp7;
    b[8] = temp8;
    b[9] = temp9;
    b[10] = temp10;
    b[11] = temp11;
    b[12] = temp12;
    b[13] = temp13;
    b[14] = temp14;
    b[15] = temp15;

    a01 += lda;
    a02 += lda;
    a03 += lda;
    a04 += lda;
    a05 += lda;
    a06 += lda;
    a07 += lda;
    a08 += lda;
    a09 += lda;
    a10 += lda;
    a11 += lda;
    a12 += lda;
    a13 += lda;
    a14 += lda;
    a15 += lda;
    a16 += lda;
    b += 16;
}
}
