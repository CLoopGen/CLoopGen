#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
ptrdiff_t stride;
uint8_t *src;
uint8_t *left;
int bottom_left_size;

uint8_t *src_storage;
uint8_t *left_storage;

void init_vars() {
    size_t data_size = 128 << 20; // 128 MB
    bottom_left_size = 32;
    stride = 4096;

    src_storage = (uint8_t*)aligned_alloc(64, data_size);
    left_storage = (uint8_t*)aligned_alloc(64, data_size);

    if (!src_storage || !left_storage) {
        abort();
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        src_storage[idx] = (uint8_t)(idx & 0xFF);
        left_storage[idx] = 0;
    }

    src = src_storage;
    left = left_storage;
}