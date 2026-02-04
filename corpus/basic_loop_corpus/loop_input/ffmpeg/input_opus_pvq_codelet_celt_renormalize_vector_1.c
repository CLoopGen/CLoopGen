#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

float *X;
int N;
int i;
float g;

void init_vars() {
    N = 67108864; // ~256MB of float data (67M elements), assuming ~0.01s runtime
    X = (float*)aligned_alloc(32, N * sizeof(float));
    if (!X) {
        exit(1);
    }
    for (int j = 0; j < N; j++) {
        X[j] = (float)(drand48() * 2.0 - 1.0); // random values between -1 and 1
    }
    i = 0;
    g = 0.0f;
}