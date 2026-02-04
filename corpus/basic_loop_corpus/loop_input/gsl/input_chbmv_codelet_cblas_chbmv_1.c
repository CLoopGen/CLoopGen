#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 1 << 23; // Approximately 64 million complex floats (256 MB), adjust for ~0.01 sec runtime
void *Y;
int incY = 1;
int i;
float beta_real = 1.5f;
float beta_imag = 0.8f;
int iy = 0;

void init_vars() {
    Y = aligned_alloc(32, N * 2 * sizeof(float));
    if (!Y) {
        exit(1);
    }
    float *y_ptr = (float *)Y;
    for (int idx = 0; idx < N * 2; idx++) {
        y_ptr[idx] = (float)(idx % 100) / 10.0f;
    }
}