#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *block;
uint8_t *scantable;
int last;
int i;
int16_t temp[64];

void init_vars() {
    const size_t data_size = 1 << 20; // ~1MB of working data

    block = (int16_t*)aligned_alloc(32, data_size * sizeof(int16_t));
    scantable = (uint8_t*)aligned_alloc(32, data_size * sizeof(uint8_t));

    for (size_t idx = 0; idx < data_size; idx++) {
        block[idx] = (int16_t)(idx & 0x7FFF);
        scantable[idx] = (uint8_t)(idx % 64); // Ensure indices fit in [0,63]
    }

    last = (int)(data_size - 1);
}