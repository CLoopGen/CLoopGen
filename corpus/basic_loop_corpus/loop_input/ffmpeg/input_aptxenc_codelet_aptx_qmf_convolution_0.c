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
    const size_t data_size = 1 << 20; // ~4MB of data (1M int32_t elements)
    sig = (int32_t *)calloc(data_size, sizeof(int32_t));
    if (!sig) {
        exit(1);
    }
    for (size_t j = 0; j < data_size; j++) {
        sig[j] = (int32_t)(j % 16);
    }
    e = 0;
    i = 0;
}