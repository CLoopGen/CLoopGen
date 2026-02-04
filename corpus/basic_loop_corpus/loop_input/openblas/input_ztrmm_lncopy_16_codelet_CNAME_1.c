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
float *a09;
float *a10;
float *a11;
float *a12;
float *a13;
float *a14;
float *a15;
float *a16;

static float b_data[32 * 4096];
static float a01_data[2 * 4096];
static float a02_data[2 * 4096];
static float a03_data[2 * 4096];
static float a04_data[2 * 4096];
static float a05_data[2 * 4096];
static float a06_data[2 * 4096];
static float a07_data[2 * 4096];
static float a08_data[2 * 4096];
static float a09_data[2 * 4096];
static float a10_data[2 * 4096];
static float a11_data[2 * 4096];
static float a12_data[2 * 4096];
static float a13_data[2 * 4096];
static float a14_data[2 * 4096];
static float a15_data[2 * 4096];
static float a16_data[2 * 4096];

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
    a09 = a09_data;
    a10 = a10_data;
    a11 = a11_data;
    a12 = a12_data;
    a13 = a13_data;
    a14 = a14_data;
    a15 = a15_data;
    a16 = a16_data;

    i = 4096;

    for (int j = 0; j < 2 * 4096; j++) {
        a01_data[j] = 1.0f;
        a02_data[j] = 2.0f;
        a03_data[j] = 3.0f;
        a04_data[j] = 4.0f;
        a05_data[j] = 5.0f;
        a06_data[j] = 6.0f;
        a07_data[j] = 7.0f;
        a08_data[j] = 8.0f;
        a09_data[j] = 9.0f;
        a10_data[j] = 10.0f;
        a11_data[j] = 11.0f;
        a12_data[j] = 12.0f;
        a13_data[j] = 13.0f;
        a14_data[j] = 14.0f;
        a15_data[j] = 15.0f;
        a16_data[j] = 16.0f;
    }

    for (int j = 0; j < 32 * 4096; j++) {
        b_data[j] = 0.0f;
    }
}