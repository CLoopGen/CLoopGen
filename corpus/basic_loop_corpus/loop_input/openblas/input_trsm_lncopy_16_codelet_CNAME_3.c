#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

#define DATA_SIZE_MB 64
#define TOTAL_FLOATS (DATA_SIZE_MB * (1 << 20) / sizeof(float))

static float *buffer = NULL;

void init_vars() {
    // Initialize m to control loop iterations
    m = TOTAL_FLOATS / 4;  // Approximate to get ~64MB of data traffic

    // Set lda stride, typical for matrix access
    lda = 1;

    // Allocate large buffer for all arrays
    buffer = (float *)aligned_alloc(64, TOTAL_FLOATS * sizeof(float));
    if (!buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize pointers into the buffer with safe offsets
    a1 = buffer;
    a2 = buffer + TOTAL_FLOATS / 4;
    b = buffer + TOTAL_FLOATS / 2;

    // Ensure ii and jj are initialized so that conditions in loop are valid
    ii = 2;
    jj = 1;  // So that (ii >= jj) is true and (ii - jj) = 1 initially

    // Initialize some values in a1 to avoid division by zero later
    for (k = 0; k < m * 2; k++) {
        *(a1 + k * lda) = 1.0F + (k % 5);
    }
    for (k = 0; k < m * 2; k++) {
        *(a2 + k * lda) = 2.0F + (k % 5);
    }
}