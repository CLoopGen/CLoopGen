#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *ao1;
extern float *ao2;
extern float *ao3;
extern float *ao4;
extern float *ao5;
extern float *ao6;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *b_local = b;
for (ii = 0; ii < i; ii++) {
    b_local[0] = ao1[0];
    b_local[1] = ao2[0];
    b_local[2] = ao3[0];
    b_local[3] = ao4[0];
    b_local[4] = ao5[0];
    b_local[5] = ao6[0];

    ao1 += lda;
    ao2 += lda;
    ao3 += lda;
    ao4 += lda;
    ao5 += lda;
    ao6 += lda;
    b_local += 6;
}
b = b_local;
}
