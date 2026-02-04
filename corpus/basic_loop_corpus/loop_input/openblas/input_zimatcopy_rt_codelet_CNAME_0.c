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

static float a_data[2048 * 1024] __attribute__((aligned(32)));
static float aptr_data[2048 * 1024] __attribute__((aligned(32)));

void init_vars() {
    a = a_data;
    aptr = aptr_data;

    for (BLASLONG idx = 0; idx < 2048 * 1024; idx++) {
        a_data[idx] = (float)(idx % 127) * 0.01f;
        aptr_data[idx] = (float)((idx + 64) % 127) * 0.02f;
    }

    rows = 1024;
    cols = 1024;
    lda = 2048;
    ib = 0;
    alpha_r = 1.5f;
    alpha_i = 0.8f;
}