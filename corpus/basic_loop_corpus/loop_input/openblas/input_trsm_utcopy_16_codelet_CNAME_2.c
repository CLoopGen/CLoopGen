#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long BLASLONG;

BLASLONG m = 100000;
BLASLONG lda = 4;
float *b;
BLASLONG i;
BLASLONG ii = 2;
BLASLONG jj = 0;
BLASLONG k;
float *a1;

void init_vars() {
    // Allocate b to be large enough: m iterations, each accessing up to ii-jj+1 elements, but b is advanced by 4 each time
    // Total size needed for b: at least m * 4 floats
    b = (float*)aligned_alloc(32, sizeof(float) * m * 4);
    if (!b) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // a1 is incremented by lda (4) each iteration, and we access up to 4 elements per iteration
    // Total rows: m, so total size: m * lda
    a1 = (float*)aligned_alloc(32, sizeof(float) * m * lda);
    if (!a1) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize a1 with non-zero values to avoid division by zero
    for (BLASLONG idx = 0; idx < m * lda; idx++) {
        a1[idx] = 1.0F + (idx % 100);
    }

    // Initialize b to zero
    memset(b, 0, sizeof(float) * m * 4);

    // Reset loop counters
    i = 0;
}