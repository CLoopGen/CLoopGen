#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef float real_t;

real_t *restrict xx;
real_t temp;

static real_t *xx_storage;

void init_vars() {
    const int array_size = 32000 / 2;
    xx_storage = (real_t*)aligned_alloc(32, array_size * sizeof(real_t));
    if (!xx_storage) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    xx = xx_storage;

    for (int i = 0; i < array_size; i++) {
        xx[i] = 1.0f;
    }

    temp = 0.0f;
}