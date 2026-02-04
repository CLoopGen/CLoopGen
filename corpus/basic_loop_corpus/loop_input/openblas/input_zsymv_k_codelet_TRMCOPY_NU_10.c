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
    const size_t size_a = m * lda * sizeof(float);
    const size_t size_b = m * m * sizeof(float);
    const size_t size_c = m * m * sizeof(float);

    a = (float *)aligned_alloc(32, size_a);
    b1 = (float *)aligned_alloc(32, size_b);
    b2 = (float *)aligned_alloc(32, size_c);

    if (!a || !b1 || !b2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < m * lda; i++) {
        a[i] = (float)(i + 1);
    }
    for (size_t i = 0; i < m * m; i++) {
        b1[i] = 0.0f;
        b2[i] = 0.0f;
    }
}