#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t coeffs[16] = {
    1, -2, 3, -4, 5, -6, 7, -8,
    9, -10, 11, -12, 13, -14, 15, -16
};

int32_t *sig;
int64_t e;
int i;

void init_vars() {
    size_t data_size = 16;
    sig = (int32_t*)aligned_alloc(32, data_size * sizeof(int32_t));
    if (!sig) {
        exit(1);
    }
    for (size_t idx = 0; idx < data_size; idx++) {
        sig[idx] = (int32_t)(idx * 3);
    }
    e = 0;
    i = 0;
}