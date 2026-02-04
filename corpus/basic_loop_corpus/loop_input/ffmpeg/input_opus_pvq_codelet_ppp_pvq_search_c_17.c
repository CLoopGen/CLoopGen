#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

float *X;
int *y;
int N;
int i;
int y_norm;
float xy_norm;
int max_idx;
int phase;
float max_num;
float max_den;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256MB of total data (adjustable)
    N = data_size / sizeof(float); // Use float as base unit

    X = (float *)aligned_alloc(32, N * sizeof(float));
    y = (int *)aligned_alloc(32, N * sizeof(int));

    if (!X || !y) {
        exit(1);
    }

    srand(0);
    for (int j = 0; j < N; j++) {
        X[j] = (float)(rand() % 1000) / 10.0f - 50.0f;
        y[j] = rand() % 200 - 100;
    }

    y_norm = 100;
    xy_norm = 50.0f;
    max_idx = 0;
    phase = 1;
    max_num = 1.0f;
    max_den = 1.0f;
    i = 0;
}