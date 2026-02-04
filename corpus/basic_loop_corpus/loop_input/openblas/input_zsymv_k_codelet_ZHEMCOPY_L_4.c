#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long BLASLONG;

BLASLONG m;
float *a;
BLASLONG lda;
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
    // Set matrix size to achieve ~0.01s runtime: use m ≈ 512-1024 based on typical performance
    m = 1024;
    
    // Leading dimension must be at least m, pad for safety
    lda = m + 8;

    // Allocate input matrix 'a': accessed with stride lda and up to (js+2)*lda + offset
    // Outer loop runs m/2 iterations, each time advancing a by 2*lda + 4
    // Total advance in 'a' over loop: (m/2) * (2*lda + 4) = m*lda + 2*m
    // So we need at least m*lda + 2*m elements
    a = (float*)aligned_alloc(32, sizeof(float) * (m * lda + 2 * m + 16));
    if (!a) exit(1);

    // b1 and b2 are output arrays, each of size roughly m * m (but accessed in blocks)
    // From loop: b1 and b2 are indexed as [0..m), then advanced by 4*m+4 per outer iteration
    // Total allocations for b1 and b2: enough to allow (m/2) steps of (4*m+4)
    size_t b_size = sizeof(float) * (m * m + 4 * m + 16);
    b1 = (float*)aligned_alloc(32, b_size);
    b2 = (float*)aligned_alloc(32, b_size);
    if (!b1 || !b2) exit(1);

    // Initialize all data to avoid NaN or extreme values
    memset(a, 0, sizeof(float) * (m * lda + 2 * m + 16));
    memset(b1, 0, b_size);
    memset(b2, 0, b_size);

    // Fill 'a' with non-zero test data to make transformation visible
    for (BLASLONG i = 0; i < m; i++) {
        for (BLASLONG j = 0; j < m; j++) {
            a[i * lda + j] = (float)(i + j * 0.01f);
        }
    }

    // Initialize working pointers to null (will be set in loop)
    aa1 = NULL;
    aa2 = NULL;
    bb1 = NULL;
    bb2 = NULL;
    cc1 = NULL;
    cc2 = NULL;

    // Initialize scalars
    a11 = 0.0f;
    a21 = 0.0f;
    a31 = 0.0f;
    a41 = 0.0f;
    a12 = 0.0f;
    a22 = 0.0f;
    a32 = 0.0f;
    a42 = 0.0f;

    // Initialize loop counters
    is = 0;
    js = 0;
}