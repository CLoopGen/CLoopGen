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
for (ii = 0; ii < 16; ii++) {
    float temp01_0 = *(a01 + 0);
    float temp01_1 = *(a01 + 1);
    float temp02_0 = *(a02 + 0);
    float temp02_1 = *(a02 + 1);
    float temp03_0 = *(a03 + 0);
    float temp03_1 = *(a03 + 1);
    float temp04_0 = *(a04 + 0);
    float temp04_1 = *(a04 + 1);
    float temp05_0 = *(a05 + 0);
    float temp05_1 = *(a05 + 1);
    float temp06_0 = *(a06 + 0);
    float temp06_1 = *(a06 + 1);
    float temp07_0 = *(a07 + 0);
    float temp07_1 = *(a07 + 1);
    float temp08_0 = *(a08 + 0);
    float temp08_1 = *(a08 + 1);
    float temp09_0 = *(a09 + 0);
    float temp09_1 = *(a09 + 1);
    float temp10_0 = *(a10 + 0);
    float temp10_1 = *(a10 + 1);
    float temp11_0 = *(a11 + 0);
    float temp11_1 = *(a11 + 1);
    float temp12_0 = *(a12 + 0);
    float temp12_1 = *(a12 + 1);
    float temp13_0 = *(a13 + 0);
    float temp13_1 = *(a13 + 1);
    float temp14_0 = *(a14 + 0);
    float temp14_1 = *(a14 + 1);
    float temp15_0 = *(a15 + 0);
    float temp15_1 = *(a15 + 1);
    float temp16_0 = *(a16 + 0);
    float temp16_1 = *(a16 + 1);

    b[0] = temp01_0;
    b[1] = temp01_1;
    b[2] = temp02_0;
    b[3] = temp02_1;
    b[4] = temp03_0;
    b[5] = temp03_1;
    b[6] = temp04_0;
    b[7] = temp04_1;
    b[8] = temp05_0;
    b[9] = temp05_1;
    b[10] = temp06_0;
    b[11] = temp06_1;
    b[12] = temp07_0;
    b[13] = temp07_1;
    b[14] = temp08_0;
    b[15] = temp08_1;
    b[16] = temp09_0;
    b[17] = temp09_1;
    b[18] = temp10_0;
    b[19] = temp10_1;
    b[20] = temp11_0;
    b[21] = temp11_1;
    b[22] = temp12_0;
    b[23] = temp12_1;
    b[24] = temp13_0;
    b[25] = temp13_1;
    b[26] = temp14_0;
    b[27] = temp14_1;
    b[28] = temp15_0;
    b[29] = temp15_1;
    b[30] = temp16_0;
    b[31] = temp16_1;

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
