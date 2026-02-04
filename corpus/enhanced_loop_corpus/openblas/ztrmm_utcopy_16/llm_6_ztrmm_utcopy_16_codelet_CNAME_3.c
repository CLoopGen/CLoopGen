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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < i; ii++) {
    float temp16 = *(a01 + 15);
    float temp15 = *(a01 + 14);
    float temp14 = *(a01 + 13);
    float temp13 = *(a01 + 12);
    float temp12 = *(a01 + 11);
    float temp11 = *(a01 + 10);
    float temp10 = *(a01 + 9);
    float temp9 = *(a01 + 8);
    float temp8 = *(a01 + 7);
    float temp7 = *(a01 + 6);
    float temp6 = *(a01 + 5);
    float temp5 = *(a01 + 4);
    float temp4 = *(a01 + 3);
    float temp3 = *(a01 + 2);
    float temp2 = *(a01 + 1);
    float temp1 = *(a01 + 0);

    b[0] = temp1;
    b[1] = temp2;
    b[2] = temp3;
    b[3] = temp4;
    b[4] = temp5;
    b[5] = temp6;
    b[6] = temp7;
    b[7] = temp8;
    b[8] = temp9;
    b[9] = temp10;
    b[10] = temp11;
    b[11] = temp12;
    b[12] = temp13;
    b[13] = temp14;
    b[14] = temp15;
    b[15] = temp16;

    a01 += lda;
    a02 += lda;
    a03 += lda;
    a04 += lda;
    a05 += lda;
    a06 += lda;
    a07 += lda;
    a08 += lda;
    b += 16;
}
}
