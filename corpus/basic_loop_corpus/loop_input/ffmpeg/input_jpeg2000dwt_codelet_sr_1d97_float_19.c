#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *p;
int i0;
int i1;
int i;

static float *p_storage;
static size_t data_size = 64 * 1024 * 1024 / sizeof(float); // ~256 MB of floats

void init_vars() {
    p_storage = (float *)aligned_alloc(32, data_size * sizeof(float));
    if (!p_storage) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        p_storage[idx] = (float)(idx % 1000) * 0.001f;
    }

    p = p_storage;
    i0 = 2;
    i1 = (int)((data_size - 2) & ~1); // Ensure i1 is even and leaves room for p[2*i+2]
}