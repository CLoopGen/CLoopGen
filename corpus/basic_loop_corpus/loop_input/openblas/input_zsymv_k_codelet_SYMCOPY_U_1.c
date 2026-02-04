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
    const size_t matrix_size = m * m * sizeof(float);
    const size_t vector_size = m * sizeof(float);
    const size_t a_size = 2 * lda * m * sizeof(float);

    a = (float*)aligned_alloc(64, a_size);
    b1 = (float*)aligned_alloc(64, matrix_size);
    b2 = (float*)aligned_alloc(64, matrix_size);

    for (size_t i = 0; i < a_size / sizeof(float); ++i) {
        a[i] = (float)(i + 1);
    }

    for (size_t i = 0; i < matrix_size / sizeof(float); ++i) {
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