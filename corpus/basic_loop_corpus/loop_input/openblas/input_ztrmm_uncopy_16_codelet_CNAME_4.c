#include <stdio.h>

typedef long BLASLONG;

float *b;
BLASLONG ii;
float *a01;
float *a02;
float *a03;
float *a04;

static float b_data[8 * 65536];
static float a01_data[2 * 65536];
static float a02_data[2 * 65536];
static float a03_data[2 * 65536];
static float a04_data[2 * 65536];

void init_vars() {
    b = b_data;
    a01 = a01_data;
    a02 = a02_data;
    a03 = a03_data;
    a04 = a04_data;

    for (int i = 0; i < 2 * 65536; i++) {
        a01_data[i] = 1.0f;
        a02_data[i] = 2.0f;
        a03_data[i] = 3.0f;
        a04_data[i] = 4.0f;
    }

    for (int i = 0; i < 8 * 65536; i++) {
        b_data[i] = 0.0f;
    }
}