#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <time.h>

float *x;
float *y;
int size;
float xm;
float ym;
float num;
float den0;
float den1;

void init_vars() {
    // Set problem size to achieve approximately 0.01 seconds on modern CPUs
    // Assuming ~1-2 GHz effective processing, aim for ~10-20 million iterations
    size = 8000000;  // 8M elements, typical balance for target runtime

    // Allocate arrays
    x = (float*)aligned_alloc(32, size * sizeof(float));
    y = (float*)aligned_alloc(32, size * sizeof(float));

    // Initialize arrays with pseudo-random data
    srand((unsigned int)time(NULL));
    for (int i = 0; i < size; i++) {
        x[i] = (float)(rand()) / RAND_MAX * 100.0f;
        y[i] = (float)(rand()) / RAND_MAX * 100.0f;
    }

    // Initialize scalar values
    xm = 50.0f;
    ym = 50.0f;
    num = 0.0f;
    den0 = 0.0f;
    den1 = 0.0f;
}