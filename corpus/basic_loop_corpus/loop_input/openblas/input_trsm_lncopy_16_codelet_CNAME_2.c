#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long BLASLONG;

BLASLONG m;
BLASLONG lda;
float *b;
BLASLONG i;
BLASLONG ii;
BLASLONG jj;
BLASLONG k;
float *a1;
float *a2;
float *a3;
float *a4;

#define DATA_SIZE_MB 64
#define TOTAL_FLOATS (DATA_SIZE_MB * (1 << 20) / sizeof(float))

static float *alloc_and_init_float_array(size_t n) {
    float *arr = (float *)aligned_alloc(64, n * sizeof(float));
    for (size_t i = 0; i < n; i++) {
        arr[i] = 1.0f + (i % 1000) * 0.001f;
    }
    return arr;
}

void init_vars() {
    // Set problem size to control runtime (~0.01 sec on modern CPU)
    m = 16384;

    // Set lda to a reasonable value for matrix stride
    lda = m + 8;

    // Set jj to 0, and ii to vary from near jj to jj + m
    jj = 0;
    ii = 2;  // Start with ii >= jj and small difference

    // Allocate large buffers to ensure memory-bound behavior and realistic timing
    size_t required_size = TOTAL_FLOATS;
    
    a1 = alloc_and_init_float_array(required_size);
    a2 = alloc_and_init_float_array(required_size);
    a3 = alloc_and_init_float_array(required_size);
    a4 = alloc_and_init_float_array(required_size);
    b  = (float *)aligned_alloc(64, required_size * sizeof(float));
    
    // Ensure that during loop execution:
    // - For the first case: (ii >= jj) && (ii - jj < 4), we access up to index (ii-jj) in a1
    // - For the second case: we always write 4 elements to b and read from a1-a4 at offset 0
    // We increment a1-a4 by one each iteration, and b by 4
    // So we need at least m elements in a1-a4, and 4*m elements in b

    // Reallocate if needed to meet access pattern
    free(a1); free(a2); free(a3); free(a4); free(b);

    a1 = alloc_and_init_float_array(m * lda + 4);
    a2 = alloc_and_init_float_array(m * lda + 4);
    a3 = alloc_and_init_float_array(m * lda + 4);
    a4 = alloc_and_init_float_array(m * lda + 4);
    b  = (float *)aligned_alloc(64, 4 * m * sizeof(float));

    // Initialize all b entries to zero to avoid undefined behavior
    memset(b, 0, 4 * m * sizeof(float));
}