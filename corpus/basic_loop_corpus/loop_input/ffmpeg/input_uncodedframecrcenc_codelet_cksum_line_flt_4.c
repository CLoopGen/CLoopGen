#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

unsigned int size;
float *p;
unsigned int a;
unsigned int b;

static float *p_storage;

void init_vars() {
    const size_t data_size = 64 * (1 << 20); // 64 MB of float data (~256M bytes)
    p_storage = (float *)aligned_alloc(32, data_size * sizeof(float));
    if (!p_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        p_storage[i] = (float)((double)rand() / RAND_MAX * 2.0 - 1.0); // Random in [-1.0, 1.0]
    }

    p = p_storage;
    size = data_size;
    a = 1;
    b = 0;
}