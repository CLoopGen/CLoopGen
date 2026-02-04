#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *quant_table;
int i;

void init_vars() {
    const size_t data_size = 256 * 1024; // ~512KB of int16_t data (256K elements)
    quant_table = (int16_t*)aligned_alloc(32, (data_size + 256) * sizeof(int16_t));
    if (!quant_table) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size + 256; idx++) {
        quant_table[idx] = (int16_t)(idx % 32768);
    }
}