#include <stdio.h>

typedef long BLASLONG;

float *b;
BLASLONG ii;
float *a01;
float *a02;
float *a03;
float *a04;

static float a01_data[512];
static float a02_data[512];
static float a03_data[512];
static float a04_data[512];
static float b_data[2048];

void init_vars() {
    a01 = a01_data;
    a02 = a02_data;
    a03 = a03_data;
    a04 = a04_data;
    b = b_data;

    for (int i = 0; i < 512; i++) {
        a01_data[i] = 1.0f;
        a02_data[i] = 2.0f;
        a03_data[i] = 3.0f;
        a04_data[i] = 4.0f;
    }
}