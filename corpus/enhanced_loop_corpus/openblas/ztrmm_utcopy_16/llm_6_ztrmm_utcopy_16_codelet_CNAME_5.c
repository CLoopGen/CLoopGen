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
for (ii = 0; ii < i; ii++) {
    float temp1 = *(a01 + 0);
    float temp2 = *(a01 + 1);
    float temp3 = *(a01 + 2);
    float temp4 = *(a01 + 3);
    float temp5 = *(a01 + 4);
    float temp6 = *(a01 + 5);
    float temp7 = *(a01 + 6);
    float temp8 = *(a01 + 7);

    b[0] = temp1;
    b[1] = temp2;
    b[2] = temp3;
    b[3] = temp4;
    b[4] = temp5;
    b[5] = temp6;
    b[6] = temp7;
    b[7] = temp8;

    a01 += lda;
    a02 += lda;
    a03 += lda;
    a04 += lda;
    b += 8;
}
}
