#include <stdio.h>

typedef long BLASLONG;

float *b;
BLASLONG ii;
float *a01;
float *a02;
float *a03;
float *a04;
float *a05;
float *a06;
float *a07;
float *a08;

static float b_data[16 * 16384];
static float a01_data[2 * 16384];
static float a02_data[2 * 16384];
static float a03_data[2 * 16384];
static float a04_data[2 * 16384];
static float a05_data[2 * 16384];
static float a06_data[2 * 16384];
static float a07_data[2 * 16384];
static float a08_data[2 * 16384];

void init_vars() {
    b = b_data;
    a01 = a01_data;
    a02 = a02_data;
    a03 = a03_data;
    a04 = a04_data;
    a05 = a05_data;
    a06 = a06_data;
    a07 = a07_data;
    a08 = a08_data;

    for (int i = 0; i < 2 * 16384; i++) {
        a01_data[i] = 1.0f;
        a02_data[i] = 2.0f;
        a03_data[i] = 3.0f;
        a04_data[i] = 4.0f;
        a05_data[i] = 5.0f;
        a06_data[i] = 6.0f;
        a07_data[i] = 7.0f;
        a08_data[i] = 8.0f;
    }

    for (int i = 0; i < 16 * 16384; i++) {
        b_data[i] = 0.0f;
    }
}