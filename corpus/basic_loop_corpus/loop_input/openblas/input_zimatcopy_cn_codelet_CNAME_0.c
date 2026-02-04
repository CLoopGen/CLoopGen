#include <stdio.h>

typedef long BLASLONG;

BLASLONG rows = 1024;
BLASLONG cols = 128;
float alpha_r = 1.5f;
float alpha_i = 0.8f;
BLASLONG lda = 2048;
BLASLONG i;
BLASLONG j;
BLASLONG ia;
float *aptr;
float a0;
float a1;

static float global_aptr_data[262144]; // 2 * rows * cols_max adjusted for lda and vector access

void init_vars() {
    for (int idx = 0; idx < 262144; idx++) {
        global_aptr_data[idx] = (float)(idx % 127);
    }
    aptr = global_aptr_data;
}