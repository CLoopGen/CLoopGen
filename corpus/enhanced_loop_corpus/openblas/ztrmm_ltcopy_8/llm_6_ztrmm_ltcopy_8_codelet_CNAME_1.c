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
    float temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8;
    temp1 = *(a01 + 0);   temp2 = *(a02 + 0);
    temp3 = *(a03 + 0);   temp4 = *(a04 + 0);
    temp5 = *(a05 + 0);   temp6 = *(a06 + 0);
    temp7 = *(a07 + 0);   temp8 = *(a08 + 0);

    b[0] = temp1;
    b[1] = temp2;
    b[2] = temp3;
    b[3] = temp4;
    b[4] = temp5;
    b[5] = temp6;
    b[6] = temp7;
    b[7] = temp8;

    temp1 = *(a01 + 1);   temp2 = *(a02 + 1);
    temp3 = *(a03 + 1);   temp4 = *(a04 + 1);
    temp5 = *(a05 + 1);   temp6 = *(a06 + 1);
    temp7 = *(a07 + 1);   temp8 = *(a08 + 1);

    b[8] = temp1;
    b[9] = temp2;
    b[10] = temp3;
    b[11] = temp4;
    b[12] = temp5;
    b[13] = temp6;
    b[14] = temp7;
    b[15] = temp8;

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
