#include <stdio.h>

typedef long BLASLONG;

float *b;
BLASLONG i;
BLASLONG ii;
float *a01;
float *a02;
float *a03;
float *a04;

static float b_data[8 * 16777216]; // ~64 MB for b (8 elements per iteration)
static float a01_data[2 * 16777216]; // ~128 MB total for input arrays (2 elements per iteration)
static float a02_data[2 * 16777216];
static float a03_data[2 * 16777216];
static float a04_data[2 * 16777216];

void init_vars() {
    b = b_data;
    a01 = a01_data;
    a02 = a02_data;
    a03 = a03_data;
    a04 = a04_data;
    i = 16777216; // Number of iterations to process all data

    for (int j = 0; j < 2 * i; j++) {
        a01_data[j] = 1.0f + j * 0.0001f;
        a02_data[j] = 2.0f + j * 0.0001f;
        a03_data[j] = 3.0f + j * 0.0001f;
        a04_data[j] = 4.0f + j * 0.0001f;
    }

    for (int j = 0; j < 8 * i; j++) {
        b_data[j] = 0.0f;
    }
}