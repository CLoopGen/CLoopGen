#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG m = 1024;
float *a;
BLASLONG lda = 1024;
BLASLONG is;
BLASLONG js;
float *aa1;
float *aa2;
float *b1;
float *b2;
float *bb1;
float *bb2;
float *cc1;
float *cc2;
float a11;
float a12;
float a21;
float a22;

void init_vars() {
    a = (float*)aligned_alloc(32, sizeof(float) * m * lda);
    b1 = (float*)aligned_alloc(32, sizeof(float) * m * m + 2 * m + 8);
    b2 = (float*)aligned_alloc(32, sizeof(float) * m * m + 2 * m + 8);

    for (int i = 0; i < m * lda; i++) {
        a[i] = (float)(i + 1);
    }

    for (int i = 0; i < m * m + 2 * m + 8; i++) {
        b1[i] = 0.0f;
        b2[i] = 0.0f;
    }
}