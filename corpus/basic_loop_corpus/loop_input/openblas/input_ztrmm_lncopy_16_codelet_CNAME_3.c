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
    i = 16384;
}