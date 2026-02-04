#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *p;
int i0;
int i1;
int i;

static float *p_storage;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64 MB of float data
    p_storage = (float *)aligned_alloc(32, data_size);
    
    if (!p_storage) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size / sizeof(float); idx++) {
        p_storage[idx] = (float)(rand()) / RAND_MAX;
    }

    p = p_storage;
    i0 = 2;  // ensures 2*i - 1 >= 1 when i starts at i0>>1
    i1 = (data_size / sizeof(float)) - 4; // ensures 2*i + 1 < array size at loop end
}