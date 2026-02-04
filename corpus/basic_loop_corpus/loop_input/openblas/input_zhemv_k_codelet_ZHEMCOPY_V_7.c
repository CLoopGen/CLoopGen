#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    // Allocate matrices and vectors based on m and lda
    a = (float*)aligned_alloc(64, sizeof(float) * lda * m);
    b1 = (float*)aligned_alloc(64, sizeof(float) * m * m * 2); // Approximate upper bound
    b2 = (float*)aligned_alloc(64, sizeof(float) * m * m * 2);

    // Initialize all matrix elements to prevent undefined behavior
    memset(a, 0, sizeof(float) * lda * m);
    memset(b1, 0, sizeof(float) * m * m * 2);
    memset(b2, 0, sizeof(float) * m * m * 2);

    // Fill 'a' with non-zero test values to simulate real data
    for (BLASLONG i = 0; i < lda * m; ++i) {
        a[i] = (float)(i % 128 + 1) * 0.01f;
    }
}