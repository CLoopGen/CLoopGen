#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG lda = 6;
float *b;
BLASLONG ii;
float *ao1;

static float *original_b = NULL;
static float *original_ao1 = NULL;

void init_vars() {
    size_t b_size = 1 << 20; // ~4MB of data (1M floats)
    size_t ao1_size = b_size * 6; // ao1 strides over multiple blocks

    original_b = (float*)malloc(b_size * sizeof(float));
    original_ao1 = (float*)malloc(ao1_size * sizeof(float));

    if (!original_b || !original_ao1) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    b = original_b;
    ao1 = original_ao1;
}