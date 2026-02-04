#include <inttypes.h>
#include <stdlib.h>

float *x;
float *y;
int N;
float xavg;
float yavg;
int i;

void init_vars() {
    N = 1 << 22; // Approximately 16 million elements, ~64 MB per array

    x = (float*)aligned_alloc(32, N * sizeof(float));
    y = (float*)aligned_alloc(32, N * sizeof(float));

    for (int j = 0; j < N; j++) {
        x[j] = 1.0f + (j % 100);
        y[j] = 2.0f + (j % 75);
    }

    xavg = 0.0f;
    yavg = 0.0f;
    i = 0;
}