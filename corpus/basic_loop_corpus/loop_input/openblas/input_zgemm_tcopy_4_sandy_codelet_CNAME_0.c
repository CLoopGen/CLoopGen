#include <stdio.h>

typedef long BLASLONG;

BLASLONG row = 1024;
BLASLONG col = 1024;

float *src;
BLASLONG srcdim = 1024;
float *dest;
BLASLONG i;
BLASLONG j;
BLASLONG ii;
float *src0;
float *src1;
float *src2;
float *src3;
float *dest0;
float *dest1;
float *dest2;

static float src_buffer[1024 * 1024];
static float dest_buffer[1024 * 1024 * 4];

void init_vars() {
    src = src_buffer;
    dest = dest_buffer;
    src0 = NULL;
    src1 = NULL;
    src2 = NULL;
    src3 = NULL;
    dest0 = NULL;
    dest1 = NULL;
    dest2 = NULL;
    i = 0;
    j = 0;
    ii = 0;

    for (int idx = 0; idx < 1024 * 1024; ++idx) {
        src_buffer[idx] = (float)(idx & 255);
    }

    for (int idx = 0; idx < 1024 * 1024 * 4; ++idx) {
        dest_buffer[idx] = 0.0f;
    }
}