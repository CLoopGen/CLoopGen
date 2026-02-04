#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG lda = 1024;
float *b;
BLASLONG ii;
float *a01;

static float *original_a01 = NULL;
static float *original_b = NULL;

#define DATA_SIZE (64 * 1024 * 1024 / sizeof(float))  // ~256 MB of floats

void init_vars() {
    original_a01 = (float*)calloc(DATA_SIZE, sizeof(float));
    original_b = (float*)calloc(DATA_SIZE, sizeof(float));

    if (!original_a01 || !original_b) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    a01 = original_a01;
    b = original_b;
}

void cleanup() {
    if (original_a01) free(original_a01);
    if (original_b) free(original_b);
}