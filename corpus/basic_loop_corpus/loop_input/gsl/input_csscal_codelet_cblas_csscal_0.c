#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
float alpha;
void *X;
int incX;
int i;
int ix;

void init_vars() {
    alpha = 1.5f;
    incX = 1;
    N = (1 << 20); // Approximately 1MB of float data: 2^20 elements * sizeof(float) ~ 4MB
    X = aligned_alloc(32, 2 * N * sizeof(float));
    ix = 0;

    float *x_ptr = (float *)X;
    for (int j = 0; j < 2 * N; j++) {
        x_ptr[j] = (float)(j + 1);
    }
}