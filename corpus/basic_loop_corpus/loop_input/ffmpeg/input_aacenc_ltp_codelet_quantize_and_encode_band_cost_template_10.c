#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

#define DATA_SIZE_MB 64
#define ARRAY_SIZE (DATA_SIZE_MB * (1 << 20) / sizeof(float))

float *in;
int size = ARRAY_SIZE;
int i;
float cost;

void init_vars() {
    in = (float*)aligned_alloc(32, size * sizeof(float));
    if (!in) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int idx = 0; idx < size; idx++) {
        in[idx] = (float)(idx % 1000) / 100.0f;
    }

    i = 0;
    cost = 0.0f;
}