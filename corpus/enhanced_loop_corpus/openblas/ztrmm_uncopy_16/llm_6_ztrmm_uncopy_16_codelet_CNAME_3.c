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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < i; ii++) {
    float temp1 = *(a01 + 0);
    float temp2 = *(a01 + 1);
    float temp3 = *(a02 + 0);
    float temp4 = *(a02 + 1);
    float temp5 = *(a03 + 0);
    float temp6 = *(a03 + 1);
    float temp7 = *(a04 + 0);
    float temp8 = *(a04 + 1);
    float temp9 = *(a05 + 0);
    float temp10 = *(a05 + 1);
    float temp11 = *(a06 + 0);
    float temp12 = *(a06 + 1);
    float temp13 = *(a07 + 0);
    float temp14 = *(a07 + 1);
    float temp15 = *(a08 + 0);
    float temp16 = *(a08 + 1);

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

    a01 += 2;
    a02 += 2;
    a03 += 2;
    a04 += 2;
    a05 += 2;
    a06 += 2;
    a07 += 2;
    a08 += 2;
    b += 16;
}
}
