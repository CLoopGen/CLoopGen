#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *block;
int q;
uint8_t *quant_matrix;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01 sec runtime
    block = (int16_t*)aligned_alloc(32, data_size);
    quant_matrix = (uint8_t*)aligned_alloc(32, 64 * sizeof(uint8_t));

    for (int idx = 0; idx < 64; idx++) {
        block[idx] = (int16_t)(idx % 1000);
        quant_matrix[idx] = (uint8_t)(idx % 256);
    }

    q = 25;
}