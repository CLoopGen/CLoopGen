#include <stdio.h>

typedef long BLASLONG;

BLASLONG rows = 1024;
BLASLONG cols = 512;
float alpha_r = 1.5f;
float alpha_i = 0.8f;
BLASLONG lda = 1024;
BLASLONG i;
BLASLONG j;
BLASLONG ia;
float *aptr;
float a0;
float a1;

static float a_buffer[1024 * 1024] __attribute__((aligned(32)));

void init_vars() {
    for (int idx = 0; idx < 1024 * 1024; idx++) {
        a_buffer[idx] = (float)(idx % 128);
    }
    aptr = a_buffer;
}