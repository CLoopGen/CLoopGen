#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *reg_raw;
uint8_t *reg_dense;
uint8_t val;

static uint8_t *reg_raw_data;
static uint8_t *reg_dense_data;

void init_vars() {
    size_t raw_size = 1 << 14;
    size_t dense_size = ((raw_size * 6) + 7) / 8 + 1;

    reg_raw_data = aligned_alloc(32, raw_size * sizeof(uint8_t));
    reg_dense_data = aligned_alloc(32, dense_size * sizeof(uint8_t));

    for (size_t i = 0; i < raw_size; i++) {
        reg_raw_data[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < dense_size; i++) {
        reg_dense_data[i] = (uint8_t)((i * 73) & 0xFF);
    }

    reg_raw = reg_raw_data;
    reg_dense = reg_dense_data;
    val = 0;
}

__attribute__((destructor))
void cleanup() {
    free(reg_raw_data);
    free(reg_dense_data);
}