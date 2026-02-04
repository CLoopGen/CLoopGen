#include <stdio.h>

typedef long BLASLONG;

float *b;
BLASLONG i;
BLASLONG ii;
float *a01;
float *a02;
float *a03;
float *a04;
float *a05;
float *a06;
float *a07;
float *a08;

static float b_data[8 * 16384];
static float a01_data[16384];
static float a02_data[16384];
static float a03_data[16384];
static float a04_data[16384];
static float a05_data[16384];
static float a06_data[16384];
static float a07_data[16384];
static float a08_data[16384];

void init_vars() {
    b = b_data;
    i = 16384;
    ii = 0;
    a01 = a01_data;
    a02 = a02_data;
    a03 = a03_data;
    a04 = a04_data;
    a05 = a05_data;
    a06 = a06_data;
    a07 = a07_data;
    a08 = a08_data;

    for (int j = 0; j < 16384; j++) {
        a01_data[j] = 1.0f + j * 0.01f;
        a02_data[j] = 2.0f + j * 0.01f;
        a03_data[j] = 3.0f + j * 0.01f;
        a04_data[j] = 4.0f + j * 0.01f;
        a05_data[j] = 5.0f + j * 0.01f;
        a06_data[j] = 6.0f + j * 0.01f;
        a07_data[j] = 7.0f + j * 0.01f;
        a08_data[j] = 8.0f + j * 0.01f;
    }

    for (int j = 0; j < 8 * 16384; j++) {
        b_data[j] = 0.0f;
    }
}