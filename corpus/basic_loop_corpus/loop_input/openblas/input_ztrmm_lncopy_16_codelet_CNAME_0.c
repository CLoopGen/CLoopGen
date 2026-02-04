#include <stdio.h>
#include <stdlib.h>

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
float *a09;
float *a10;
float *a11;
float *a12;
float *a13;
float *a14;
float *a15;
float *a16;

#define LOOP_COUNT 16
#define DATA_SIZE_PER_ARRAY (32 * 1024 * 1024 / sizeof(float)) // ~16MB total input data
#define B_SIZE (LOOP_COUNT * 32)

static float a01_data[DATA_SIZE_PER_ARRAY];
static float a02_data[DATA_SIZE_PER_ARRAY];
static float a03_data[DATA_SIZE_PER_ARRAY];
static float a04_data[DATA_SIZE_PER_ARRAY];
static float a05_data[DATA_SIZE_PER_ARRAY];
static float a06_data[DATA_SIZE_PER_ARRAY];
static float a07_data[DATA_SIZE_PER_ARRAY];
static float a08_data[DATA_SIZE_PER_ARRAY];
static float a09_data[DATA_SIZE_PER_ARRAY];
static float a10_data[DATA_SIZE_PER_ARRAY];
static float a11_data[DATA_SIZE_PER_ARRAY];
static float a12_data[DATA_SIZE_PER_ARRAY];
static float a13_data[DATA_SIZE_PER_ARRAY];
static float a14_data[DATA_SIZE_PER_ARRAY];
static float a15_data[DATA_SIZE_PER_ARRAY];
static float a16_data[DATA_SIZE_PER_ARRAY];

static float b_data[B_SIZE];

void init_vars() {
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
    b = b_data;

    for (int i = 0; i < DATA_SIZE_PER_ARRAY; i++) {
        a01_data[i] = 1.0f;
        a02_data[i] = 2.0f;
        a03_data[i] = 3.0f;
        a04_data[i] = 4.0f;
        a05_data[i] = 5.0f;
        a06_data[i] = 6.0f;
        a07_data[i] = 7.0f;
        a08_data[i] = 8.0f;
        a09_data[i] = 9.0f;
        a10_data[i] = 10.0f;
        a11_data[i] = 11.0f;
        a12_data[i] = 12.0f;
        a13_data[i] = 13.0f;
        a14_data[i] = 14.0f;
        a15_data[i] = 15.0f;
        a16_data[i] = 16.0f;
    }

    for (int i = 0; i < B_SIZE; i++) {
        b_data[i] = 0.0f;
    }
}