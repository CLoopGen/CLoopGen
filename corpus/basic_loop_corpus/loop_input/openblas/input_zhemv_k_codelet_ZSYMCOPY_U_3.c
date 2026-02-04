#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG m = 512;
float *a;
BLASLONG lda = 512;
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
float a21;
float a31;
float a41;
float a12;
float a22;
float a32;
float a42;

void init_vars() {
    a = (float*)aligned_alloc(32, sizeof(float) * m * lda);
    b1 = (float*)aligned_alloc(32, sizeof(float) * 4 * m * ((m + 1) / 2 + 1));
    b2 = (float*)aligned_alloc(32, sizeof(float) * 4 * m * ((m + 1) / 2 + 1));

    for (int i = 0; i < m * lda; i++) {
        a[i] = (float)(i % 100) / 10.0f;
    }

    for (int i = 0; i < 4 * m * ((m + 1) / 2 + 1); i++) {
        b1[i] = 0.0f;
        b2[i] = 0.0f;
    }
}