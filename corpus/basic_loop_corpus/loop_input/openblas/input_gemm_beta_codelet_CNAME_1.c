#include <stdio.h>

typedef long BLASLONG;

BLASLONG n = 1000;
float beta = 2.0f;
BLASLONG ldc = 2048;
BLASLONG i;
BLASLONG j;
BLASLONG chunk = 250;
BLASLONG remain = 0;
float *c_offset1;
float *c_offset;

#define C_SIZE (2048 * 1000)
static float c_buffer[C_SIZE];

void init_vars() {
    n = 1000;
    beta = 2.0f;
    ldc = 2048;
    chunk = 250;
    remain = 0;
    c_offset = c_buffer;
}