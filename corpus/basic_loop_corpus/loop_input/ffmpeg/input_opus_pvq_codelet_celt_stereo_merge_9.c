#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

float *X;
float *Y;
float mid;
int N;
int i;
float gain[2];

void init_vars() {
    N = 1 << 20; // Approximately 1 million elements for ~0.01 sec runtime

    X = (float*)malloc(N * sizeof(float));
    Y = (float*)malloc(N * sizeof(float));

    mid = 0.5f;
    gain[0] = 0.8f;
    gain[1] = 1.2f;

    for (int j = 0; j < N; j++) {
        X[j] = (float)(j % 100) * 0.01f;
        Y[j] = (float)((j + 10) % 77) * 0.02f;
    }
}