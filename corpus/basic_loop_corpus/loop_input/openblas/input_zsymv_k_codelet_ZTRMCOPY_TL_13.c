#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG m = 1024;
float *a;
BLASLONG lda = 1028;
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
    BLASLONG size_a = (m / 2) * (2 * lda + 4) + 8;
    a = (float*)aligned_alloc(32, size_a * sizeof(float));
    
    BLASLONG size_b = (m / 2) * (4 * m + 4) + 8;
    b1 = (float*)aligned_alloc(32, size_b * sizeof(float));
    b2 = (float*)aligned_alloc(32, size_b * sizeof(float));

    for (BLASLONG i = 0; i < size_a; i++) {
        a[i] = (float)(i % 100) / 10.0f;
    }
    for (BLASLONG i = 0; i < size_b; i++) {
        b1[i] = 0.0f;
        b2[i] = 0.0f;
    }
}