#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    const size_t a_size = (2 * lda + 4) * ((m + 1) / 2);
    a = (float*)aligned_alloc(32, a_size * sizeof(float));
    
    const size_t b_size = (4 * m + 4) * ((m + 1) / 2);
    b1 = (float*)aligned_alloc(32, b_size * sizeof(float));
    b2 = (float*)aligned_alloc(32, b_size * sizeof(float));

    for (size_t i = 0; i < a_size; i++) {
        a[i] = (float)(i * 0.5f);
    }
    for (size_t i = 0; i < b_size; i++) {
        b1[i] = 0.0f;
        b2[i] = 0.0f;
    }

    js = 0;
}