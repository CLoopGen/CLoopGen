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
    float temp01 = *(a01 + 0);
    float temp02 = *(a01 + 1);
    float temp03 = *(a01 + 2);
    float temp04 = *(a01 + 3);
    float temp05 = *(a01 + 4);
    float temp06 = *(a01 + 5);
    float temp07 = *(a01 + 6);
    float temp08 = *(a01 + 7);
    float temp09 = *(a01 + 8);
    float temp10 = *(a01 + 9);
    float temp11 = *(a01 + 10);
    float temp12 = *(a01 + 11);
    float temp13 = *(a01 + 12);
    float temp14 = *(a01 + 13);
    float temp15 = *(a01 + 14);
    float temp16 = *(a01 + 15);
    float temp17 = *(a01 + 16);
    float temp18 = *(a01 + 17);
    float temp19 = *(a01 + 18);
    float temp20 = *(a01 + 19);
    float temp21 = *(a01 + 20);
    float temp22 = *(a01 + 21);
    float temp23 = *(a01 + 22);
    float temp24 = *(a01 + 23);
    float temp25 = *(a01 + 24);
    float temp26 = *(a01 + 25);
    float temp27 = *(a01 + 26);
    float temp28 = *(a01 + 27);
    float temp29 = *(a01 + 28);
    float temp30 = *(a01 + 29);
    float temp31 = *(a01 + 30);
    float temp32 = *(a01 + 31);

    b[0] = temp01;
    b[1] = temp02;
    b[2] = temp03;
    b[3] = temp04;
    b[4] = temp05;
    b[5] = temp06;
    b[6] = temp07;
    b[7] = temp08;
    b[8] = temp09;
    b[9] = temp10;
    b[10] = temp11;
    b[11] = temp12;
    b[12] = temp13;
    b[13] = temp14;
    b[14] = temp15;
    b[15] = temp16;
    b[16] = temp17;
    b[17] = temp18;
    b[18] = temp19;
    b[19] = temp20;
    b[20] = temp21;
    b[21] = temp22;
    b[22] = temp23;
    b[23] = temp24;
    b[24] = temp25;
    b[25] = temp26;
    b[26] = temp27;
    b[27] = temp28;
    b[28] = temp29;
    b[29] = temp30;
    b[30] = temp31;
    b[31] = temp32;

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
    b += 32;
}
}
