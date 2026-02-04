#include <stdio.h>

typedef long BLASLONG;

BLASLONG rows = 1024;
BLASLONG cols = 1024;
float alpha = 1.5f;
float *a;
BLASLONG lda = 1024;
BLASLONG i;
BLASLONG j;
float *aptr;
float *bptr;
float tmp;

static float a_data[1024 * 1024] __attribute__((aligned(32)));
static float aptr_data[1024 * 1024] __attribute__((aligned(32)));

void init_vars() {
    a = a_data;
    aptr = aptr_data;

    for (BLASLONG idx = 0; idx < rows * cols; idx++) {
        a_data[idx] = (float)(idx % 123);
    }
    for (BLASLONG idx = 0; idx < rows * cols; idx++) {
        aptr_data[idx] = (float)(idx % 456);
    }
}