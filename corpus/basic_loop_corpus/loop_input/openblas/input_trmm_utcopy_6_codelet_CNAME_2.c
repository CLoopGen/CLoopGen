#include <stdlib.h>

typedef long BLASLONG;

BLASLONG lda;
float *b;
BLASLONG ii;
float *ao1;

static float *original_ao1;
static float *original_b;
static BLASLONG total_size = 67108864; // ~256MB of floats (67M elements)

void init_vars() {
    original_ao1 = (float*)aligned_alloc(32, total_size * sizeof(float));
    original_b = (float*)aligned_alloc(32, total_size * sizeof(float));

    for (BLASLONG i = 0; i < total_size; i++) {
        original_ao1[i] = 1.0f;
        original_b[i] = 0.0f;
    }

    ao1 = original_ao1;
    b = original_b;
    lda = 4;
}