#include <stdio.h>

typedef long BLASLONG;

BLASLONG rows = 2048;
BLASLONG cols = 128;
float alpha = 1.5f;
BLASLONG lda = 2048;
BLASLONG i;
BLASLONG j;
float *aptr;

static float a_buffer[262144]; // 2048 * 128 = 262144 elements, ~1MB

void init_vars() {
    for (int idx = 0; idx < 262144; idx++) {
        a_buffer[idx] = (float)(idx % 1000) / 100.0f;
    }
    aptr = a_buffer;
}