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

static float *alloc_aligned_float_array(size_t n) {
    void *ptr;
    if (posix_memalign(&ptr, 32, n * sizeof(float)) != 0) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    return (float*)ptr;
}

void init_vars() {
    // Set matrix size to achieve ~0.01 seconds runtime
    // Empirical testing suggests m around 2000-3000 gives reasonable timing
    m = 2500;

    // Ensure m is at least 2 and handle odd/even correctly
    if (m < 2) m = 2;

    // Set leading dimension with padding to avoid cache conflicts
    lda = m + 8;

    // Allocate matrix 'a': accessed with offsets up to (m-1)*lda + (m+3)
    // We access a up to roughly (m) * lda + 4*m, so allocate accordingly
    a = alloc_aligned_float_array(lda * m + 16);

    // Allocate b1 and b2: each needs space for m*m elements with stride m
    // Each block writes to 4*stride locations per iteration
    b1 = alloc_aligned_float_array(m * m + 16);
    b2 = alloc_aligned_float_array(m * m + 16);

    // Initialize all memory to prevent undefined behavior in stores
    memset(a, 0, (lda * m + 16) * sizeof(float));
    memset(b1, 0, (m * m + 16) * sizeof(float));
    memset(b2, 0, (m * m + 16) * sizeof(float));

    // Initialize pointer temporals to NULL (will be set in loop)
    aa1 = NULL;
    aa2 = NULL;
    bb1 = NULL;
    bb2 = NULL;
    cc1 = NULL;
    cc2 = NULL;

    // Initialize scalar temps
    a11 = 0.0f;
    a21 = 0.0f;
    a31 = 0.0f;
    a41 = 0.0f;
    a12 = 0.0f;
    a22 = 0.0f;
    a32 = 0.0f;
    a42 = 0.0f;

    // Initialize loop indices
    is = 0;
    js = 0;
}