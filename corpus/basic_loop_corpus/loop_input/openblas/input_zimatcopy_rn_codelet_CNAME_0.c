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

static float a_array[1024 * 1024] __attribute__((aligned(32))); // ~4MB of data

void init_vars() {
    for (int k = 0; k < 1024 * 1024; k++) {
        a_array[k] = (float)(k % 128) / 64.0f;
    }
    aptr = a_array;
}