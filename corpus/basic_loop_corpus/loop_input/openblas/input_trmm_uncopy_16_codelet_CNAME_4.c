#include <stdio.h>

typedef long BLASLONG;

float *b;
BLASLONG ii;
float *a01;
float *a02;
float *a03;
float *a04;

static float b_data[1024 * 1024 / sizeof(float)]; // ~1MB for b
static float a01_data[1024 * 1024 / sizeof(float)]; // ~1MB for each a*
static float a02_data[1024 * 1024 / sizeof(float)];
static float a03_data[1024 * 1024 / sizeof(float)];
static float a04_data[1024 * 1024 / sizeof(float)];

void init_vars() {
    b = b_data;
    a01 = a01_data;
    a02 = a02_data;
    a03 = a03_data;
    a04 = a04_data;

    for (int i = 0; i < 1024 * 1024 / sizeof(float); i++) {
        a01_data[i] = 1.0f + i;
        a02_data[i] = 2.0f + i;
        a03_data[i] = 3.0f + i;
        a04_data[i] = 4.0f + i;
        b_data[i] = 0.0f;
    }
}