#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t val;
uint8_t *reg_raw;
uint8_t *reg_dense;

static uint8_t *raw_buffer;
static uint8_t *dense_buffer;

void init_vars() {
    size_t data_size = 1 << 20; // 1MB of data
    raw_buffer = aligned_alloc(64, data_size);
    dense_buffer = aligned_alloc(64, data_size);

    if (!raw_buffer || !dense_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        raw_buffer[i] = rand() & 0xFF;
        dense_buffer[i] = rand() & 0xFF;
    }

    reg_raw = raw_buffer;
    reg_dense = dense_buffer;
}