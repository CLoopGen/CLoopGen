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
    // Allocate matrices with size m x m
    a = (float*)aligned_alloc(32, sizeof(float) * m * lda);
    b1 = (float*)aligned_alloc(32, sizeof(float) * m * m);
    b2 = (float*)aligned_alloc(32, sizeof(float) * m * m);

    // Initialize all matrix elements to avoid undefined behavior
    for (int i = 0; i < m * lda; i++) {
        a[i] = (float)(i + 1);
    }
    for (int i = 0; i < m * m; i++) {
        b1[i] = 0.0f;
        b2[i] = 0.0f;
    }

    // Ensure m is even or handle edge cases properly
    // Original loop assumes m >= 1 and handles m-js == 1 case
    // We set m=1024 which is sufficiently large and power of two

    // Initialize pointers to prevent use-before-assign in analysis
    aa1 = a;
    aa2 = a + lda;
    bb1 = b1;
    bb2 = b1 + m;
    cc1 = b2;
    cc2 = b2 + m;
}