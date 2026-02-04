#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *top;
int i;
uint8_t v[31];

static uint8_t *buffer;

void init_vars() {
    size_t data_size = 1 << 20; // 1MB of input data for ~0.01 sec runtime
    buffer = (uint8_t*)aligned_alloc(32, data_size);
    if (!buffer) {
        exit(1);
    }

    top = buffer;
    for (size_t j = 0; j < data_size; j++) {
        buffer[j] = (uint8_t)(j % 251);
    }
}

__attribute__((destructor))
static void cleanup() {
    free(buffer);
}