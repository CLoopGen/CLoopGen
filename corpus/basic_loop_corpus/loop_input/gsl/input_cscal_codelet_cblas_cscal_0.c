#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int N;
void *X;
int incX;
int i;
int ix;
float alpha_real;
float alpha_imag;

void init_vars() {
    alpha_real = 0.8f;
    alpha_imag = 0.6f;
    incX = 1;
    N = (1 << 23); // Approximately 67 million complex numbers -> ~512MB, ensures loop runs long enough
    size_t data_size = 2 * N * sizeof(float);
    X = aligned_alloc(32, data_size);
    if (!X) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    memset(X, 0, data_size);
    float *x_float = (float *)X;
    for (int j = 0; j < N; j++) {
        size_t idx = 2 * (j * incX);
        x_float[idx]     = 1.0f + j % 10;
        x_float[idx + 1] = 0.5f + j % 10;
    }
    ix = 0;
}