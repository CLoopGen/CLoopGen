#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int idx;
uint8_t *s;
uint8_t *d;

static uint8_t *s_storage;
static uint8_t *d_storage;

void init_vars() {
    const size_t data_size = 1 << 20; // 1 MB of data

    s_storage = aligned_alloc(32, data_size);
    d_storage = aligned_alloc(32, data_size);

    if (!s_storage || !d_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        s_storage[i] = rand() & 0xFF;
        d_storage[i] = 0;
    }

    s = s_storage;
    d = d_storage;
    idx = 0;
}

__attribute__((destructor))
static void cleanup() {
    free(s_storage);
    free(d_storage);
}