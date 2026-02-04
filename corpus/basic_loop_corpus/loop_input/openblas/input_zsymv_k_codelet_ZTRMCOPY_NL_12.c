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
    const size_t total_size_a = (m / 2) * (lda + 2) * sizeof(float);
    const size_t total_size_b = (m / 2) * (m + 1) * 4 * sizeof(float) * 2; // Approximate for b1 and b2

    a = aligned_alloc(32, total_size_a);
    b1 = aligned_alloc(32, total_size_b);
    b2 = b1 + (total_size_b / sizeof(float)) / 2;

    if (!a || !b1 || !b2) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (BLASLONG i = 0; i < total_size_a / sizeof(float); ++i) {
        a[i] = (float)(i * 0.01f);
    }
    for (BLASLONG i = 0; i < total_size_b / sizeof(float); ++i) {
        b1[i] = 0.0f;
    }
}