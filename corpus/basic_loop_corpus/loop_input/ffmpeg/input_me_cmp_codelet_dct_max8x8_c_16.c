#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *temp;
int sum;
int i;

static size_t data_size = 1 << 20; // 1MB of data: 1M elements * 2 bytes = 2MB

void init_vars() {
    temp = (int16_t *)aligned_alloc(_Alignof(int16_t), data_size * sizeof(int16_t));
    if (!temp) {
        exit(1);
    }
    for (size_t j = 0; j < data_size; j++) {
        temp[j] = rand() % 65536 - 32768;
    }
    sum = 0;
    i = 0;
}