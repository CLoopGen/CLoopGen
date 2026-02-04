#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *vector_buf;
int16_t size;
unsigned int val;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of int32_t data for sufficient runtime (~0.01 sec on modern CPU)
    vector_buf = (int32_t*)aligned_alloc(_Alignof(int32_t), data_size);
    if (!vector_buf) exit(1);

    for (size_t idx = 0; idx < data_size / sizeof(int32_t); ++idx) {
        vector_buf[idx] = rand() % 2000 - 1000; // Random values in [-1000, 999]
    }

    size = (int16_t)(data_size / sizeof(int32_t)); // Ensure no out-of-bounds access
    val = 0;
    i = 0;
}