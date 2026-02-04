#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG m = 512;
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
float a21;
float a31;
float a41;
float a12;
float a22;
float a32;
float a42;

void init_vars() {
    a = (float*)aligned_alloc(64, sizeof(float) * lda * m);
    b1 = (float*)aligned_alloc(64, sizeof(float) * m * m);
    b2 = (float*)aligned_alloc(64, sizeof(float) * m * m);

    for (int i = 0; i < lda * m; i++) {
        a[i] = (float)(i + 1);
    }
    for (int i = 0; i < m * m; i++) {
        b1[i] = 0.0f;
        b2[i] = 0.0f;
    }

    aa1 = NULL;
    aa2 = NULL;
    bb1 = NULL;
    bb2 = NULL;
    cc1 = NULL;
    cc2 = NULL;
    is = 0;
    js = 0;
    a11 = 0.0f;
    a21 = 0.0f;
    a31 = 0.0f;
    a41 = 0.0f;
    a12 = 0.0f;
    a22 = 0.0f;
    a32 = 0.0f;
    a42 = 0.0f;
}