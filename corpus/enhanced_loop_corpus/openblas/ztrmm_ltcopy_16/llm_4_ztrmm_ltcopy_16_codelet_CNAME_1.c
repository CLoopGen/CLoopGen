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
    if (ii % 2 == 0) {
        b[0] = *(a01 + 0);
        b[1] = *(a01 + 1);
        b[2] = *(a01 + 2);
        b[3] = *(a01 + 3);
        b[4] = *(a01 + 4);
        b[5] = *(a01 + 5);
        b[6] = *(a01 + 6);
        b[7] = *(a01 + 7);
        b[8] = *(a01 + 8);
        b[9] = *(a01 + 9);
        b[10] = *(a01 + 10);
        b[11] = *(a01 + 11);
        b[12] = *(a01 + 12);
        b[13] = *(a01 + 13);
        b[14] = *(a01 + 14);
        b[15] = *(a01 + 15);
        b[16] = *(a01 + 16);
        b[17] = *(a01 + 17);
        b[18] = *(a01 + 18);
        b[19] = *(a01 + 19);
        b[20] = *(a01 + 20);
        b[21] = *(a01 + 21);
        b[22] = *(a01 + 22);
        b[23] = *(a01 + 23);
        b[24] = *(a01 + 24);
        b[25] = *(a01 + 25);
        b[26] = *(a01 + 26);
        b[27] = *(a01 + 27);
        b[28] = *(a01 + 28);
        b[29] = *(a01 + 29);
        b[30] = *(a01 + 30);
        b[31] = *(a01 + 31);
    } else {
        for (int j = 0; j < 32; j++) {
            b[j] = *(a01 + j);
        }
    }
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
