#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *top;
int i;
uint8_t v[15];

static uint8_t *buffer;

void init_vars() {
    size_t data_size = 1 << 20; // 1MB of data
    buffer = (uint8_t*)calloc(data_size, sizeof(uint8_t));
    if (!buffer) {
        exit(1);
    }

    top = buffer;

    for (size_t idx = 0; idx < data_size; ++idx) {
        buffer[idx] = (uint8_t)(idx % 251);
    }
}

__attribute__((constructor))
void initialize() {
    init_vars();
}