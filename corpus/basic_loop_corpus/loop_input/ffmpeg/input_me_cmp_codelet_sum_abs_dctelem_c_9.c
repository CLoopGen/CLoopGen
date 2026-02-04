#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *block;
int sum;
int i;

static const size_t data_size = 128 * 1024 * 1024; // 128 MB of data

void init_vars() {
    block = (int16_t*)aligned_alloc(_Alignof(int16_t), data_size);
    if (!block) {
        exit(1);
    }
    for (size_t j = 0; j < data_size / sizeof(int16_t); ++j) {
        block[j] = (int16_t)(j % 65536 - 32768);
    }
    sum = 0;
    i = 0;
}