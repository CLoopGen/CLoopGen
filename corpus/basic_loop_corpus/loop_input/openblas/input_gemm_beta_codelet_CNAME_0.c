#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG n = 2048;
BLASLONG ldc = 2056;
BLASLONG i;
BLASLONG j;
BLASLONG chunk = 256;
BLASLONG remain = 8;
float *c_offset1;
float *c_offset;

static float *c_buffer = NULL;

void init_vars() {
    BLASLONG total_size = n * ldc;
    c_buffer = (float*)calloc(total_size, sizeof(float));
    c_offset = c_buffer;
}