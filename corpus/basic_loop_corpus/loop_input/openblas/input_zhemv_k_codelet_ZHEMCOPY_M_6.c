#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG m = 1024;
float *a;
BLASLONG lda = 2048;
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
    const size_t matrix_size = m * m;
    const size_t a_size = (2 * lda + 4) * ((m + 1) / 2 + 1);
    const size_t b_size = (4 * m + 4) * ((m + 1) / 2 + 1);

    a = (float*)aligned_alloc(32, sizeof(float) * a_size);
    b1 = (float*)aligned_alloc(32, sizeof(float) * b_size);
    b2 = (float*)aligned_alloc(32, sizeof(float) * b_size);

    for (size_t i = 0; i < a_size; i++) {
        a[i] = (float)(i % 100) * 0.1f;
    }
    for (size_t i = 0; i < b_size; i++) {
        b1[i] = 0.0f;
        b2[i] = 0.0f;
    }

    is = 0;
    js = 0;
    aa1 = NULL;
    aa2 = NULL;
    bb1 = NULL;
    bb2 = NULL;
    cc1 = NULL;
    cc2 = NULL;
    a11 = 0.0f;
    a21 = 0.0f;
    a31 = 0.0f;
    a41 = 0.0f;
    a12 = 0.0f;
    a22 = 0.0f;
    a32 = 0.0f;
    a42 = 0.0f;
}