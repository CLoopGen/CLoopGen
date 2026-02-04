#include <stdlib.h>

typedef long BLASLONG;

BLASLONG lda;
float *b;
BLASLONG i;
BLASLONG ii;
float *a01;

static float *original_a01;
static float *original_b;

void init_vars() {
    i = 65536; // Number of iterations
    lda = 4;   // Leading dimension

    original_a01 = (float*)aligned_alloc(64, sizeof(float) * (lda * i + 4));
    original_b = (float*)aligned_alloc(64, sizeof(float) * (4 * i + 4));

    if (!original_a01 || !original_b) {
        exit(1);
    }

    a01 = original_a01;
    b = original_b;

    for (BLASLONG idx = 0; idx < lda * i + 4; idx++) {
        original_a01[idx] = (float)(idx % 1000) / 1000.0f;
    }
    for (BLASLONG idx = 0; idx < 4 * i + 4; idx++) {
        original_b[idx] = 0.0f;
    }
}

__attribute__((constructor)) void initialize() {
    init_vars();
}