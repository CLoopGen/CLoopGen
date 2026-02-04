#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int N;
float alpha;
float *X;
float *Y;
int i;
int m;

void init_vars() {
    // Set problem size to achieve around 0.01 seconds runtime
    // Assuming moderate CPU speed and cache effects, use ~64M floats (256 MB total for two arrays)
    N = 16000000;  // 16M elements, ensures i+3 < N is valid with step 4

    // Initialize alpha to a non-zero value
    alpha = 1.5f;

    // Set loop starting point
    m = 0;

    // Allocate aligned memory for better performance
    X = (float*)aligned_alloc(32, N * sizeof(float));
    Y = (float*)aligned_alloc(32, N * sizeof(float));

    // Initialize arrays to avoid undefined behavior
    for (int j = 0; j < N; j++) {
        X[j] = (float)(j % 100) / 100.0f;
        Y[j] = (float)(j % 50) / 50.0f;
    }
}