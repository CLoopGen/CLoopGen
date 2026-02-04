#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *p;
int i0;
int i1;
int i;

static int *p_storage;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate
    p_storage = (int*)aligned_alloc(32, data_size);
    if (!p_storage) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size / sizeof(int); idx++) {
        p_storage[idx] = rand();
    }

    p = p_storage;
    i0 = 2;
    i1 = (data_size / sizeof(int)) - 2;
}