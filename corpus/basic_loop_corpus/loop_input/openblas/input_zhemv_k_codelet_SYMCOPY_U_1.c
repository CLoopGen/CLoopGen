#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG m;
float *a;
BLASLONG lda;
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
    m = 1024;
    lda = m;

    a = (float*)aligned_alloc(32, sizeof(float) * lda * m);
    b1 = (float*)aligned_alloc(32, sizeof(float) * m * m);
    b2 = (float*)aligned_alloc(32, sizeof(float) * m * m);

    for (BLASLONG i = 0; i < lda * m; i++) {
        a[i] = (float)(i + 1);
    }
    for (BLASLONG i = 0; i < m * m; i++) {
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
    a12 = 0.0f;
    a21 = 0.0f;
    a22 = 0.0f;
}