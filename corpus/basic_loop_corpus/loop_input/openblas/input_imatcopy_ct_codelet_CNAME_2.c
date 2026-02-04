#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG rows;
BLASLONG cols;
float *a;
BLASLONG lda;
BLASLONG i;
BLASLONG j;
float *aptr;
float *bptr;
float tmp;

void init_vars() {
    // Set matrix dimensions to achieve ~0.01s runtime
    // Empirically, with O(n^2) complexity in the loop, a size of around 2000x2000
    // gives reasonable timing (adjustable based on typical CPU)
    rows = 2048;
    cols = 2048;
    lda = rows;  // leading dimension typically >= rows

    // Total memory size: cols * lda elements -> 2048*2048 ≈ 4M floats ≈ 16.8 MB
    a = (float*)aligned_alloc(64, sizeof(float) * lda * cols);
    if (!a) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize aptr to start of matrix
    aptr = a;

    // Initialize all matrix elements to prevent undefined behavior
    for (BLASLONG k = 0; k < lda * cols; k++) {
        a[k] = (float)(k % 100) / 100.0f;
    }
}