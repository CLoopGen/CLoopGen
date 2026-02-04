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
float a21;
float a31;
float a41;
float a12;
float a22;
float a32;
float a42;

void init_vars() {
    a = (float*)aligned_alloc(64, sizeof(float) * m * lda);
    b1 = (float*)aligned_alloc(64, sizeof(float) * 4 * m * ((m + 1)/2));
    b2 = (float*)aligned_alloc(64, sizeof(float) * 4 * m * ((m + 1)/2));

    if (!a || !b1 || !b2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (BLASLONG i = 0; i < m * lda; i++) {
        a[i] = (float)(i + 1);
    }
    for (BLASLONG i = 0; i < 4 * m * ((m + 1)/2); i++) {
        b1[i] = 0.0f;
        b2[i] = 0.0f;
    }
}