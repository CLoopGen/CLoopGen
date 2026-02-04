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
    const size_t size_a = (size_t)lda * (size_t)m;
    const size_t size_b = (size_t)m * (size_t)m;
    
    a = (float*)aligned_alloc(32, size_a * sizeof(float));
    b1 = (float*)aligned_alloc(32, size_b * sizeof(float));
    b2 = (float*)aligned_alloc(32, size_b * sizeof(float));

    for (size_t i = 0; i < size_a; i++) {
        a[i] = (float)(i + 1);
    }
    for (size_t i = 0; i < size_b; i++) {
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