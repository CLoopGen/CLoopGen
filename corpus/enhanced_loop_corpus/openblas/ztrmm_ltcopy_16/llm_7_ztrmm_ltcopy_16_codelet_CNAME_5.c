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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *a1, *a2, *a3, *a4;
for (ii = 0; ii < i; ii++) {
    a1 = a01 + 0; a2 = a02 + 0; a3 = a03 + 0; a4 = a04 + 0;
    b[0] = a1[0] + a2[0] + a3[0] + a4[0];
    b[1] = a1[1] + a2[1] + a3[1] + a4[1];
    b[2] = a1[2] + a2[2] + a3[2] + a4[2];
    b[3] = a1[3] + a2[3] + a3[3] + a4[3];
    b[4] = a1[4] + a2[4] + a3[4] + a4[4];
    b[5] = a1[5] + a2[5] + a3[5] + a4[5];
    b[6] = a1[6] + a2[6] + a3[6] + a4[6];
    b[7] = a1[7] + a2[7] + a3[7] + a4[7];
    a01 += lda;
    a02 += lda;
    a03 += lda;
    a04 += lda;
    b += 8;
}
}
