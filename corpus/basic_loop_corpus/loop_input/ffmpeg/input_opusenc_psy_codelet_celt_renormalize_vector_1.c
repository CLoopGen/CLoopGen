#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

float *X;
int N = 65536; 
int i;
float g;

void init_vars() {
    const size_t data_size = N * sizeof(float);
    X = (float*)aligned_alloc(32, data_size);
    if (!X) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int j = 0; j < N; j++) {
        X[j] = (float)(rand() % 100) / 10.0f;
    }

    i = 0;
    g = 0.0f;
}