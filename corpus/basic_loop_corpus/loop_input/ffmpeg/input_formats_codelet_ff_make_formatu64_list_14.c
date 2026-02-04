#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint64_t *fmts;
int count;

static uint64_t *fmts_storage;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; // 128 MB
    fmts_storage = malloc(data_size);
    if (!fmts_storage) {
        exit(1);
    }

    size_t num_elements = data_size / sizeof(uint64_t);
    for (size_t i = 0; i < num_elements - 1; i++) {
        fmts_storage[i] = i + 1;
    }
    fmts_storage[num_elements - 1] = -1ULL;

    fmts = fmts_storage;
    count = 0;
}