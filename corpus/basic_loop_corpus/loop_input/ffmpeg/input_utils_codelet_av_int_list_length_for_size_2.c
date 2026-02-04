#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int i;
uint32_t t;
uint32_t *l;

static uint32_t *l_storage;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB of data
    l_storage = aligned_alloc(32, data_size);
    if (!l_storage) {
        exit(1);
    }

    for (size_t idx = 0; idx < (data_size / sizeof(uint32_t)) - 1; idx++) {
        l_storage[idx] = 0xFFFFFFFFU;
    }

    t = 0xFFFFFFF0U;
    l_storage[(data_size / sizeof(uint32_t)) - 1] = t;

    l = l_storage;
    i = 0;
}