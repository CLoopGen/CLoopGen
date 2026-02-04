#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 1048576; // Approximately 8MB of data (1M complex float pairs)

void *X;
void *Y;
int incX = 1;
int incY = 1;
int i;
int ix = 0;
int iy = 0;

void init_vars() {
    X = aligned_alloc(32, 2 * N * sizeof(float));
    Y = aligned_alloc(32, 2 * N * sizeof(float));

    if (!X || !Y) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    float *xf = (float *)X;
    float *yf = (float *)Y;

    for (int idx = 0; idx < 2 * N; idx++) {
        xf[idx] = (float)(idx % 100) + 0.1f;
        yf[idx] = (float)((idx + 10) % 100) + 0.2f;
    }
}