#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *bits;
unsigned int num;
unsigned int i;
unsigned int p;

static uint8_t *internal_bits;
static size_t data_size = 1 << 20; // 1MB

void init_vars() {
    internal_bits = calloc(data_size, sizeof(uint8_t));
    if (!internal_bits) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size * 7 / 8; ++idx) {
        internal_bits[idx] = 0;
    }
    for (size_t idx = data_size * 7 / 8; idx < data_size; ++idx) {
        internal_bits[idx] = 1;
    }

    bits = internal_bits;
    num = data_size;
    p = data_size / 4;
}