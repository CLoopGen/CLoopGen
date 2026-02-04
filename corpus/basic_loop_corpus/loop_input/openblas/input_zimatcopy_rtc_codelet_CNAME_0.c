#include <stdlib.h>
#include <string.h>

typedef long BLASLONG;

BLASLONG rows = 1024;
BLASLONG cols = 1024;
float alpha_r = 1.5f;
float alpha_i = 0.8f;
float *a;
BLASLONG lda = 1024;
BLASLONG i;
BLASLONG j;
BLASLONG ia;
BLASLONG ib = 0;
float *aptr;
float *bptr;
float t0;
float t1;

void init_vars() {
    size_t total_size = (size_t)lda * cols * 2 * sizeof(float);
    a = (float*)aligned_alloc(32, total_size);
    if (!a) exit(1);
    memset(a, 0, total_size);
    aptr = a;
}