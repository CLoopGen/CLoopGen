#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *top;
int i;
uint8_t v[7];

static uint8_t *buffer;

void init_vars() {
    size_t data_size = 1 << 20; // 1MB of input data
    buffer = (uint8_t*)calloc(data_size, sizeof(uint8_t));
    if (!buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        buffer[idx] = (uint8_t)(idx % 256);
    }

    top = buffer;
}

__attribute__((destructor))
static void cleanup() {
    free(buffer);
}