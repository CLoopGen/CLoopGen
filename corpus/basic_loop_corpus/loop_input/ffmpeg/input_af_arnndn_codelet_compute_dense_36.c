#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *output;
int N;

void init_vars() {
    N = 67108864; // Approximately 256 MB for float array (67M elements)
    output = (float *)aligned_alloc(32, N * sizeof(float));
    if (!output) {
        exit(1);
    }
    for (int i = 0; i < N; i++) {
        output[i] = (float)(i % 256 - 128); // Sample values in range [-128, 127]
    }
}