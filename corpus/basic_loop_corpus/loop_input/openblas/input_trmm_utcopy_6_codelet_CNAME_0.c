#include <stdlib.h>
#include <stdio.h>

typedef long BLASLONG;

BLASLONG lda;
float *b;
BLASLONG ii;
float *ao1;

static float *original_ao1;
static float *original_b;
static size_t total_size;

void init_vars() {
    const int num_iterations = 6;
    const int block_size = 6;
    total_size = 256 * 1024 * 1024; // 256 MB total data

    original_ao1 = (float*)aligned_alloc(32, total_size);
    original_b = (float*)aligned_alloc(32, total_size);

    if (!original_ao1 || !original_b) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size / sizeof(float); i++) {
        original_ao1[i] = (float)(i % 1000) + 1.0f;
        original_b[i] = 0.0f;
    }

    lda = block_size;
    ao1 = original_ao1;
    b = original_b;
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}

__attribute__((destructor))
static void destructor_free() {
    free(original_ao1);
    free(original_b);
}