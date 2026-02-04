#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 1 << 24; // Approximately 67 million iterations for ~0.01 sec estimate
void *Y;
int incY = 1;
int i;
float beta_real = 1.5f;
float beta_imag = 0.8f;
int iy = 0;

void init_vars() {
    const size_t total_elements = 2 * (iy + (N - 1) * incY + 1);
    Y = aligned_alloc(32, total_elements * sizeof(float));
    if (!Y) {
        exit(1);
    }
    float *y_float = (float *)Y;
    for (size_t idx = 0; idx < total_elements; ++idx) {
        y_float[idx] = (float)(idx % 128) * 0.1f;
    }
}