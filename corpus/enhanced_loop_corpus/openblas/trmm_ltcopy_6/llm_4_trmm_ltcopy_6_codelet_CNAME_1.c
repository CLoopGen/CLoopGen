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
        if (ii % 2 == 0) {
            b[0] = ao1[0];
            b[1] = ao1[1];
            b[2] = ao1[2];
            b[3] = ao1[3];
            b[4] = ao1[4];
            b[5] = ao1[5];
        } else {
            b[0] = 0.0f;
            b[1] = 0.0f;
            b[2] = 0.0f;
            b[3] = 0.0f;
            b[4] = 0.0f;
            b[5] = 0.0f;
        }
        ao1 += lda;
        ao2 += lda;
        ao3 += lda;
        ao4 += lda;
        ao5 += lda;
        ao6 += lda;
        b += 6;
    }
}
