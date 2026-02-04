#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *top;
int i;
uint8_t v[31];

static uint8_t *buffer;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; // 256 MB to target ~0.01 sec runtime
    buffer = (uint8_t*)aligned_alloc(32, data_size);
    if (!buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        buffer[idx] = (uint8_t)(idx % 256);
    }

    top = buffer;
}

__attribute__((destructor))
void cleanup() {
    free(buffer);
}