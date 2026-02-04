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

static float b_data[256 * 1024];        // 1MB buffer for b (256k floats)
static float a01_data[64 * 1024];       // Shared size for all aXX arrays
static float a02_data[64 * 1024];
static float a03_data[64 * 1024];
static float a04_data[64 * 1024];
static float a05_data[64 * 1024];
static float a06_data[64 * 1024];
static float a07_data[64 * 1024];
static float a08_data[64 * 1024];
static float a09_data[64 * 1024];
static float a10_data[64 * 1024];
static float a11_data[64 * 1024];
static float a12_data[64 * 1024];
static float a13_data[64 * 1024];
static float a14_data[64 * 1024];
static float a15_data[64 * 1024];
static float a16_data[64 * 1024];

void init_vars() {
    const int total_iters = 4096;      // Number of iterations to run (~0.01 sec estimate)
    const int block_size = 16;
    
    // Ensure each aXX array has at least total_iters elements
    i = total_iters;
    
    // Initialize pointers to start of data arrays
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
    
    // Initialize b pointer to beginning of b_data
    b = b_data;
    
    // Initialize input data to prevent undefined behavior
    for (int j = 0; j < total_iters; j++) {
        if (j < 64 * 1024) {
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
    }
}