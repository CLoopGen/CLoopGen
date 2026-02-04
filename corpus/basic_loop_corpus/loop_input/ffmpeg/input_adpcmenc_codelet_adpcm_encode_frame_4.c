#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int n;
int i;
uint8_t *dst;
uint8_t *buf;

static uint8_t *dst_storage;
static uint8_t *buf_storage;

void init_vars() {
    size_t data_size = 128 << 20; // 128 MB input data size

    buf_storage = aligned_alloc(32, data_size);
    dst_storage = aligned_alloc(32, data_size / 2);

    if (!buf_storage || !dst_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        buf_storage[idx] = rand() & 0xFF;
    }

    n = data_size - (data_size % 2); // Ensure n is even so buf[i+1] is valid
    i = 0;
    buf = buf_storage;
    dst = dst_storage;
}