#include <stdio.h>

typedef long BLASLONG;

BLASLONG m = 1024;
BLASLONG n = 256;
BLASLONG ldc = 1024;
BLASLONG i;
BLASLONG j;

float *c_offset;
float *c_offset1;

static float c_buffer[1024 * 1024] __attribute__((aligned(32)));

void init_vars() {
    c_offset = c_buffer;
    c_offset1 = c_buffer;
}

void loop();