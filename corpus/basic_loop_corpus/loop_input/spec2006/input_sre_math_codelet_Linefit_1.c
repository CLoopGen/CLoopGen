#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

float *x;
float *y;
int N;
float xavg;
float yavg;
float sxx;
float syy;
float sxy;
int i;

void init_vars() {
    const int data_size = 64 * 1024 * 1024; // ~256 MB for two float arrays (64M elements each)
    N = data_size / sizeof(float);
    
    x = (float*)aligned_alloc(32, N * sizeof(float));
    y = (float*)aligned_alloc(32, N * sizeof(float));

    if (!x || !y) {
        exit(1);
    }

    xavg = 1.5f;
    yavg = 2.5f;
    sxx = 0.0f;
    syy = 0.0f;
    sxy = 0.0f;

    srand(1);
    for (int j = 0; j < N; j++) {
        x[j] = (rand() % 1000) / 100.0f;
        y[j] = (rand() % 1000) / 100.0f;
    }
}