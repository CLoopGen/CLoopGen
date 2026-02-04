#include <stdio.h>

typedef long BLASLONG;

BLASLONG row;
BLASLONG i;
BLASLONG ii;

float *src0;
float *src1;
float *src2;
float *src3;
float *dest0;

static float src0_data[256 * 1024] __attribute__((aligned(32)));
static float src1_data[256 * 1024] __attribute__((aligned(32)));
static float src2_data[256 * 1024] __attribute__((aligned(32)));
static float src3_data[256 * 1024] __attribute__((aligned(32)));
static float dest_data[1024 * 1024] __attribute__((aligned(32)));

void init_vars() {
    row = 32768;
    src0 = src0_data;
    src1 = src1_data;
    src2 = src2_data;
    src3 = src3_data;
    dest0 = dest_data;

    for (int j = 0; j < 256 * 1024; j++) {
        src0_data[j] = 1.0f + j * 0.0001f;
        src1_data[j] = 2.0f + j * 0.0001f;
        src2_data[j] = 3.0f + j * 0.0001f;
        src3_data[j] = 4.0f + j * 0.0001f;
    }

    for (int j = 0; j < 1024 * 1024; j++) {
        dest_data[j] = 0.0f;
    }
}