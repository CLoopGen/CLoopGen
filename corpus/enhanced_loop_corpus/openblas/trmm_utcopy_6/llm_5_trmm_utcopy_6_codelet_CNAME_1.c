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
for (ii = 0; ii < i; ii++) {
    float *src = ao1;
    if (ii >= i / 2) {
        src = ao3;
    }
    b[0] = src[0];
    b[1] = src[1];
    b[2] = src[2];
    b[3] = src[3];
    b[4] = src[4];
    b[5] = src[5];
    ao1 += lda;
    ao2 += lda;
    ao3 += lda;
    ao4 += lda;
    ao5 += lda;
    ao6 += lda;
    b += 6;
}
}
