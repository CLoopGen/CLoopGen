#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *block;
ptrdiff_t stride;
int height;
int y;

static uint8_t *block_storage;

void init_vars() {
    size_t total_size = 64 * 1024 * 1024; // ~64 MB to target ~0.01 sec runtime
    stride = 8192; // Sufficiently large stride for spatial behavior
    height = total_size / stride;

    block_storage = aligned_alloc(32, total_size);
    if (!block_storage) {
        exit(1);
    }
    block = block_storage;
}

__attribute__((destructor))
static void cleanup() {
    free(block_storage);
}