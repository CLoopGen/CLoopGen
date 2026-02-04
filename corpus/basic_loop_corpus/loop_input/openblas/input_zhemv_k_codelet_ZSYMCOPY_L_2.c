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
    // Allocate matrices with sufficient size to prevent out-of-bounds access
    // Based on loop logic: we access up to a + (2*lda + 4) * (m/2) and similar for b1, b2
    // Max js ~ m-2, so total outer iterations ~ m/2
    // Total advance in 'a' is about (2*lda + 4) * (m/2) = m*lda + 2*m
    // So allocate at least m*lda + 2*m + 16 floats for safety

    BLASLONG a_size = m * lda + 2 * m + 16;
    a = (float*)aligned_alloc(32, a_size * sizeof(float));
    
    // b1 and b2 are used as destination buffers with access patterns:
    // b1 += 4*m + 4 per iteration, total ~ (m/2)*(4*m + 4) = 2*m^2 + 2*m
    // Similarly for b2. Also cc1/cc2 use 4*m stride -> need large enough buffer
    BLASLONG b_size = 2 * m * m + 8 * m + 16;
    b1 = (float*)aligned_alloc(32, b_size * sizeof(float));
    b2 = (float*)aligned_alloc(32, b_size * sizeof(float));

    // Initialize all pointer variables to avoid undefined behavior
    aa1 = a;
    aa2 = a;
    bb1 = b1;
    bb2 = b1;
    cc1 = b2;
    cc2 = b2;

    // Initialize array contents to prevent floating point issues
    for (BLASLONG i = 0; i < a_size; i++) {
        a[i] = (float)(i % 100) / 100.0f;
    }
    for (BLASLONG i = 0; i < b_size; i++) {
        b1[i] = 0.0f;
        b2[i] = 0.0f;
    }

    // Reset critical variables that are modified in loop
    is = 0;
    js = 0;
    a11 = 0.0f; a21 = 0.0f; a31 = 0.0f; a41 = 0.0f;
    a12 = 0.0f; a22 = 0.0f; a32 = 0.0f; a42 = 0.0f;
}