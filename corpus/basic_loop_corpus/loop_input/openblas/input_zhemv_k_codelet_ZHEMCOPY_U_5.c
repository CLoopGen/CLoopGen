#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG m = 512;
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
    // Allocate matrix 'a' with size at least m x (lda) but we use larger for safety
    a = (float*)aligned_alloc(64, sizeof(float) * lda * m * 2);
    
    // Allocate b1 and b2: each needs space for m * m elements
    b1 = (float*)aligned_alloc(64, sizeof(float) * m * m * 2);
    b2 = (float*)aligned_alloc(64, sizeof(float) * m * m * 2);

    // Initialize all arrays to avoid undefined behavior
    for (BLASLONG i = 0; i < lda * m * 2; i++) {
        a[i] = (float)(i % 100) / 100.0f;
    }
    for (BLASLONG i = 0; i < m * m * 2; i++) {
        b1[i] = 0.0f;
        b2[i] = 0.0f;
    }

    // Ensure m is even for predictable behavior or handle odd case correctly
    if (m <= 0) m = 512;
}