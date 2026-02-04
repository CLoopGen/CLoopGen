#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *coef;
int i;
int32_t tmp[64];

static int32_t coef_data[64];

void init_vars() {
    const size_t data_size = 64 * sizeof(int32_t);
    coef = coef_data;

    for (size_t idx = 0; idx < 64; idx++) {
        coef[idx] = (int32_t)(idx * idx + 1);
    }

    i = 0;

    for (int j = 0; j < 64; j++) {
        tmp[j] = 0;
    }
}