#include <stdio.h>

typedef long BLASLONG;

BLASLONG row;
BLASLONG col;
BLASLONG i;
BLASLONG ii;
float *src0;
float *src1;
float *dest0;

static float src0_data[256 * 1024] __attribute__((aligned(32)));
static float src1_data[256 * 1024] __attribute__((aligned(32)));
static float dest_data[512 * 1024] __attribute__((aligned(32)));

void init_vars() {
    row = 16;
    col = 16384;  

    src0 = src0_data;
    src1 = src1_data;
    dest0 = dest_data;

    for (int j = 0; j < 256 * 1024; j++) {
        src0_data[j] = 1.0f;
        src1_data[j] = 2.0f;
    }
}