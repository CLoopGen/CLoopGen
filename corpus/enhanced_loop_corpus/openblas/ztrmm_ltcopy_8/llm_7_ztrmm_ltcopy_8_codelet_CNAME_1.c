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
float *b_local = b;
for (ii = 0; ii < i; ii++) {
    b_local[0]  = *(a01 + 0);
    b_local[1]  = *(a01 + 1);
    b_local[2]  = *(a01 + 2);
    b_local[3]  = *(a01 + 3);
    b_local[4]  = *(a01 + 4);
    b_local[5]  = *(a01 + 5);
    b_local[6]  = *(a01 + 6);
    b_local[7]  = *(a01 + 7);
    b_local[8]  = *(a01 + 8);
    b_local[9]  = *(a01 + 9);
    b_local[10] = *(a01 + 10);
    b_local[11] = *(a01 + 11);
    b_local[12] = *(a01 + 12);
    b_local[13] = *(a01 + 13);
    b_local[14] = *(a01 + 14);
    b_local[15] = *(a01 + 15);

    a01 += lda;
    a02 += lda;
    a03 += lda;
    a04 += lda;
    a05 += lda;
    a06 += lda;
    a07 += lda;
    a08 += lda;

    b_local += 16;
}

b = b_local; 
}
