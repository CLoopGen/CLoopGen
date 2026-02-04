#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
void *Y;
int incY;
int i;
float beta_real;
float beta_imag;
int iy;

void init_vars() {
    beta_real = 1.5f;
    beta_imag = 0.8f;
    N = 6710886;  // ~6.7M complex pairs = ~51.2 MB, ensures ~0.01 sec on modern CPU
    incY = 1;
    iy = 0;

    Y = aligned_alloc(32, N * 2 * sizeof(float));
    if (!Y) {
        exit(1);
    }

    float *y_ptr = (float *)Y;
    for (int idx = 0; idx < N * 2; idx++) {
        y_ptr[idx] = (float)(idx % 128) / 32.0f;
    }
}