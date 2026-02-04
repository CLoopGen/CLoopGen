#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int n;
int i;
uint8_t *dst;
uint8_t *buf;

uint8_t *buf_storage;
uint8_t *dst_storage;

void init_vars() {
    size_t data_size = 128 << 20; // 128 MB of input data for sufficient runtime (~0.01 sec on modern CPU)
    buf_storage = (uint8_t*)aligned_alloc(32, data_size);
    dst_storage = (uint8_t*)aligned_alloc(32, data_size / 2);

    if (!buf_storage || !dst_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize buffer with non-zero pattern to make operations observable
    for (size_t idx = 0; idx < data_size; ++idx) {
        buf_storage[idx] = (uint8_t)(idx & 0xFF);
    }

    // Set up pointers
    buf = buf_storage;
    dst = dst_storage;

    // Ensure loop runs over valid even-sized range: n must be even and within bounds
    n = (int)(data_size & ~1); // Round down to even number
}