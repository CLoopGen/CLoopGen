#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *coef;
int i;
int32_t tmp[16];

void init_vars() {
    const size_t data_size = 1 << 20;
    coef = aligned_alloc(32, data_size * sizeof(int32_t));
    for (size_t idx = 0; idx < data_size; ++idx) {
        coef[idx] = (int32_t)(idx % 1000);
    }
    for (int idx = 0; idx < 16; ++idx) {
        tmp[idx] = (int32_t)(idx * 7);
    }
}