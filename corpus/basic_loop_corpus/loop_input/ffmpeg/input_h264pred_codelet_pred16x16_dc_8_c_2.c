#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

ptrdiff_t stride;
int i;
int dc;
uint8_t *src;

static uint8_t *src_storage;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of input data
    src_storage = aligned_alloc(64, data_size);
    if (!src_storage) abort();

    for (size_t idx = 0; idx < data_size; ++idx) {
        src_storage[idx] = rand() & 0xFF;
    }

    stride = 64; 
    dc = 0;
    src = src_storage + 1; // Ensure src[-1] is valid: point to offset 1
}

__attribute__((destructor))
static void cleanup() {
    free(src_storage);
}