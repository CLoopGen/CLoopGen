#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG lda;
float *b;
BLASLONG ii;
float *ao1;

static float *original_ao1;
static float *original_b;
static const BLASLONG data_size = 64 * 1024 * 1024 / sizeof(float); // ~256MB total data

void init_vars() {
    original_ao1 = (float*)calloc(data_size, sizeof(float));
    original_b = (float*)calloc(data_size, sizeof(float));

    if (!original_ao1 || !original_b) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    ao1 = original_ao1;
    b = original_b;
    lda = 4; // stride between successive ao1 rows
}

void cleanup_vars() {
    free(original_ao1);
    free(original_b);
}