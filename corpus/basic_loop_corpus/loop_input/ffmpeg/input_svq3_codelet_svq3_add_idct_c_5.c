#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *block;
int i;

void init_vars() {
    const size_t data_size = 1 << 20;
    block = (int16_t*)aligned_alloc(32, data_size * sizeof(int16_t));
    if (!block) {
        exit(1);
    }
    for (size_t idx = 0; idx < data_size; ++idx) {
        block[idx] = (int16_t)(idx % 32767);
    }
}