#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *reg_raw;
uint8_t *reg_dense;
uint8_t val;

static uint8_t *reg_raw_storage;
static uint8_t *reg_dense_storage;

void init_vars() {
    size_t data_size = 1 << 20; // 1MB of data
    reg_raw_storage = aligned_alloc(64, data_size);
    reg_dense_storage = aligned_alloc(64, data_size);

    for (size_t i = 0; i < data_size; i++) {
        reg_raw_storage[i] = rand() & 0xFF;
        reg_dense_storage[i] = rand() & 0xFF;
    }

    reg_raw = reg_raw_storage;
    reg_dense = reg_dense_storage;
    val = 0;
}