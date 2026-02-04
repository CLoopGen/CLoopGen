#include <stdint.h>
#include <stdlib.h>

int8_t n_coeffs;
int16_t *block_dup;
int32_t cnt;

static int16_t *block_dup_storage;

void init_vars() {
    size_t data_size = 1 << 20;
    n_coeffs = (int8_t)(data_size / sizeof(int16_t));
    block_dup_storage = (int16_t *)calloc(data_size, 1);
    block_dup = block_dup_storage - 8;
}