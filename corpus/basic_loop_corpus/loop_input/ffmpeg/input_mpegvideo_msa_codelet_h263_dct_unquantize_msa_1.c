#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *block;
int16_t qmul;
int16_t qadd;
int8_t n_coeffs;
int32_t level;
int32_t cnt;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB of data
    int16_t *data = aligned_alloc(32, data_size);
    if (!data) {
        exit(1);
    }

    for (size_t i = 0; i < data_size / sizeof(int16_t); i++) {
        data[i] = (int16_t)(rand() % 201 - 100); // Random values in [-100, 100]
    }

    block = data;
    qmul = 31;
    qadd = 17;
    n_coeffs = (int8_t)((data_size / sizeof(int16_t)) - 1);
    level = 0;
    cnt = 0;
}