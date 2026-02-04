#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

float *tmp;
float *X;
int N0;
int stride;
int i;
int j;
uint8_t *order;

#define TOTAL_DATA_SIZE (128 << 20)  // Aim for ~128 MB of total data

void init_vars() {
    // Set dimensions to ensure about 128 MB of data
    // The main arrays are tmp and X, each of size N0 * stride (in elements)
    // Each element is float (4 bytes), so total memory ~ 2 * N0 * stride * 4 = 8 * N0 * stride
    // We want 8 * N0 * stride ≈ 128 MB => N0 * stride ≈ 16M
    // Choose balanced values: let’s set N0 = 4096, then stride = 4096 → 4096*4096 = 16.7M
    N0 = 4096;
    stride = 4096;

    // Allocate tmp and X
    tmp = (float*)aligned_alloc(32, N0 * stride * sizeof(float));
    X = (float*)aligned_alloc(32, N0 * stride * sizeof(float));
    order = (uint8_t*)malloc(stride * sizeof(uint8_t));

    // Initialize order array with valid indices into [0, stride) range
    for (int idx = 0; idx < stride; idx++) {
        order[idx] = (uint8_t)(idx % 256);
        if (order[idx] >= stride) {
            order[idx] = idx % stride;  // fallback to safe index
        }
    }

    // Initialize X with some data to avoid undefined behavior
    for (int idx = 0; idx < N0 * stride; idx++) {
        X[idx] = (float)(rand() / (double)RAND_MAX);
    }

    // Initialize tmp to zero
    memset(tmp, 0, N0 * stride * sizeof(float));
}