#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG lda;
float *b;
BLASLONG ii;
float *a01;

static float *original_a;
static float *original_b;

void init_vars() {
    BLASLONG total_size = 64 * 1024 * 1024; // ~256 MB of float data

    original_a = (float*)calloc(total_size, sizeof(float));
    original_b = (float*)calloc(total_size, sizeof(float));

    if (!original_a || !original_b) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    a01 = original_a;
    b = original_b;
    lda = 4; // stride between consecutive rows

    // Ensure loop runs safely: 4 iterations with 4 elements each
    for (BLASLONG i = 0; i < 16; i++) {
        original_a[i] = 1.0f; // arbitrary initialization
    }
}

// Cleanup to prevent memory leaks (not required by problem but good practice)
void cleanup_vars() {
    free(original_a);
    free(original_b);
}