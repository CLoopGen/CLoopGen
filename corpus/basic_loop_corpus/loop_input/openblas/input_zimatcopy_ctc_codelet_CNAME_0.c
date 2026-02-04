#include <stdio.h>

typedef long BLASLONG;

BLASLONG rows = 1024;
BLASLONG cols = 1024;
float alpha_r = 1.5f;
float alpha_i = 0.8f;
float *a;
BLASLONG lda = 2048;
BLASLONG i;
BLASLONG j;
BLASLONG ia;
BLASLONG ib = 0;
float *aptr;
float *bptr;
float t0;
float t1;

void init_vars() {
    const size_t total_size = (size_t)lda * rows * sizeof(float);
    a = (float*)__builtin_malloc(total_size);
    aptr = a;

    for (size_t idx = 0; idx < (size_t)lda * rows; ++idx) {
        a[idx] = (float)(idx % 100) / 100.0f;
    }
}