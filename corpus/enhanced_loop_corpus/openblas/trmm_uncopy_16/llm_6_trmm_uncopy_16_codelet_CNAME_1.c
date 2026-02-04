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
    float temp2 = *(a02 + 0);
    float temp3 = *(a03 + 0);
    float temp4 = *(a04 + 0);
    float temp5 = *(a05 + 0);
    float temp6 = *(a06 + 0);
    float temp7 = *(a07 + 0);
    float temp8 = *(a08 + 0);
    float temp9 = *(a09 + 0);
    float temp10 = *(a10 + 0);
    float temp11 = *(a11 + 0);
    float temp12 = *(a12 + 0);
    float temp13 = *(a13 + 0);
    float temp14 = *(a14 + 0);
    float temp15 = *(a15 + 0);
    float temp16 = *(a16 + 0);

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

    a01++;
    a02++;
    a03++;
    a04++;
    a05++;
    a06++;
    a07++;
    a08++;
    a09++;
    a10++;
    a11++;
    a12++;
    a13++;
    a14++;
    a15++;
    a16++;
    b += 16;
}
}
