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
    float temp1 = *(a01 + 0);
    float temp2 = *(a01 + 1);
    b[0] = temp1;
    b[1] = temp2;

    temp1 = *(a02 + 0);
    temp2 = *(a02 + 1);
    b[2] = temp1;
    b[3] = temp2;

    temp1 = *(a03 + 0);
    temp2 = *(a03 + 1);
    b[4] = temp1;
    b[5] = temp2;

    temp1 = *(a04 + 0);
    temp2 = *(a04 + 1);
    b[6] = temp1;
    b[7] = temp2;

    temp1 = *(a05 + 0);
    temp2 = *(a05 + 1);
    b[8] = temp1;
    b[9] = temp2;

    temp1 = *(a06 + 0);
    temp2 = *(a06 + 1);
    b[10] = temp1;
    b[11] = temp2;

    temp1 = *(a07 + 0);
    temp2 = *(a07 + 1);
    b[12] = temp1;
    b[13] = temp2;

    temp1 = *(a08 + 0);
    temp2 = *(a08 + 1);
    b[14] = temp1;
    b[15] = temp2;

    temp1 = *(a09 + 0);
    temp2 = *(a09 + 1);
    b[16] = temp1;
    b[17] = temp2;

    temp1 = *(a10 + 0);
    temp2 = *(a10 + 1);
    b[18] = temp1;
    b[19] = temp2;

    temp1 = *(a11 + 0);
    temp2 = *(a11 + 1);
    b[20] = temp1;
    b[21] = temp2;

    temp1 = *(a12 + 0);
    temp2 = *(a12 + 1);
    b[22] = temp1;
    b[23] = temp2;

    temp1 = *(a13 + 0);
    temp2 = *(a13 + 1);
    b[24] = temp1;
    b[25] = temp2;

    temp1 = *(a14 + 0);
    temp2 = *(a14 + 1);
    b[26] = temp1;
    b[27] = temp2;

    temp1 = *(a15 + 0);
    temp2 = *(a15 + 1);
    b[28] = temp1;
    b[29] = temp2;

    temp1 = *(a16 + 0);
    temp2 = *(a16 + 1);
    b[30] = temp1;
    b[31] = temp2;

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
