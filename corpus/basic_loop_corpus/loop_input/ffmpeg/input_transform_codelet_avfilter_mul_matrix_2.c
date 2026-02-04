#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE_MB 64
#define ARRAY_SIZE (DATA_SIZE_MB * 1024 * 1024 / sizeof(float))

float *m1;
float scalar;
float *result;
int i;

void init_vars() {
    scalar = 2.5f;

    m1 = (float *)aligned_alloc(32, ARRAY_SIZE * sizeof(float));
    result = (float *)aligned_alloc(32, ARRAY_SIZE * sizeof(float));

    if (!m1 || !result) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < ARRAY_SIZE; idx++) {
        m1[idx] = (float)(idx % 1000) + 0.5f;
        result[idx] = 0.0f;
    }

    i = 0;
}