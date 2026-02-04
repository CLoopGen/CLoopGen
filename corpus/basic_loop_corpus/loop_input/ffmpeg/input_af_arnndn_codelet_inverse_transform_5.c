#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

#define BUFFER_SIZE (2 * (120 << 2))

float *out;
AVComplexFloat y[BUFFER_SIZE];

void init_vars() {
    out = (float*)aligned_alloc(32, BUFFER_SIZE * sizeof(float));
    if (!out) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < BUFFER_SIZE; i++) {
        y[i].re = (float)(i * 2 + 1);
        y[i].im = (float)(i * 2);
        out[i] = 0.0f;
    }
}