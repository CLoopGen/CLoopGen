#include <stdio.h>

typedef long BLASLONG;

BLASLONG row;
BLASLONG i;
BLASLONG ii;

float *src0;
float *src1;
float *dest0;

static float src0_data[65536];
static float src1_data[65536];
static float dest0_data[131072];

void init_vars() {
    row = 8192;

    src0 = src0_data;
    src1 = src1_data;
    dest0 = dest0_data;
}