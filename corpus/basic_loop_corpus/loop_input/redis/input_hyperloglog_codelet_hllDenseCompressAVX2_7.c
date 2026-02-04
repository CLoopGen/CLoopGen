#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE (64 * 1024 * 1024) // 64 MB for ~0.01 sec runtime estimate

uint8_t *reg_dense;
uint8_t *reg_raw;

static uint8_t internal_reg_dense[DATA_SIZE];
static uint8_t internal_reg_raw[1 << 14];

void init_vars() {
    reg_dense = internal_reg_dense;
    reg_raw = internal_reg_raw;

    for (int i = 0; i < (1 << 14); i++) {
        reg_raw[i] = (uint8_t)(i * 7 + 3);
    }

    for (size_t i = 0; i < DATA_SIZE; i++) {
        internal_reg_dense[i] = (uint8_t)(i * 31);
    }
}