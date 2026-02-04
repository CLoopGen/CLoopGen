#include <stdlib.h>
#include <stdio.h>

typedef long BLASLONG;

BLASLONG lda;
float *b;
BLASLONG ii;
float *a01;

static float *buffer_a = NULL;
static float *buffer_b = NULL;

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB total data size

void init_vars() {
    // Allocate aligned memory to mimic high-performance computing environment
    buffer_a = (float*)aligned_alloc(32, DATA_SIZE);
    buffer_b = (float*)aligned_alloc(32, DATA_SIZE);

    if (!buffer_a || !buffer_b) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize lda to a reasonable value (number of columns in matrix)
    lda = 16; // Ensures sufficient stride for memory access

    // Initialize a01 and b to point into the allocated buffers
    a01 = buffer_a;
    b = buffer_b;

    // Initialize input data to avoid undefined values
    for (size_t i = 0; i < DATA_SIZE / sizeof(float); i++) {
        buffer_a[i] = (float)(i % 100) / 100.0f;
        buffer_b[i] = 0.0f;
    }
}