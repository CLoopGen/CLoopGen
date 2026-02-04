#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *reg_dense;
uint8_t *reg_raw;

static uint8_t *dense_buffer;
static uint8_t *raw_buffer;

void init_vars() {
    size_t raw_size = 1 << 14;
    size_t dense_size = ((raw_size * 6) + 7) / 8 + 1;

    raw_buffer = calloc(raw_size, sizeof(uint8_t));
    dense_buffer = calloc(dense_size, sizeof(uint8_t));

    if (!raw_buffer || !dense_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < raw_size; i++) {
        raw_buffer[i] = (uint8_t)(i * 7919) & 0x3F;
    }

    reg_raw = raw_buffer;
    reg_dense = dense_buffer;
}