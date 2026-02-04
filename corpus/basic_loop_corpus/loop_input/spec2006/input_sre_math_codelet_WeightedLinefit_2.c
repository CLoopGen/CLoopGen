#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

float *x;
float *y;
float *var;
int N;
int i;
double s;
double sx;
double sy;
double sxx;
double sxy;

void init_vars() {
    N = 16777216; // Approximately 64 MB of data (16M elements * 4 bytes per float * 4 arrays)

    x = (float*)aligned_alloc(32, N * sizeof(float));
    y = (float*)aligned_alloc(32, N * sizeof(float));
    var = (float*)aligned_alloc(32, N * sizeof(float));

    for (int idx = 0; idx < N; idx++) {
        x[idx] = 1.0f + (idx % 100);
        y[idx] = 2.0f + (idx % 75);
        var[idx] = 0.5f + (idx % 50);
    }

    s = 0.0;
    sx = 0.0;
    sy = 0.0;
    sxx = 0.0;
    sxy = 0.0;
    i = 0;
}