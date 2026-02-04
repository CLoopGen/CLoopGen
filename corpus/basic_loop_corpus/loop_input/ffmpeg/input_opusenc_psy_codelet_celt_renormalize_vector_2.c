#include <stdlib.h>
#include <stdint.h>

float *X;
int N;
int i;
float g;

void init_vars() {
    N = 1 << 24; // Approximately 67M elements, ~256MB for float
    X = (float*)aligned_alloc(32, N * sizeof(float));
    g = 1.5f;
    for (int j = 0; j < N; j++) {
        X[j] = (float)(j % 100);
    }
}