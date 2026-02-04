#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int end_x;
int n;
uint8_t *a;

void init_vars() {
    size_t data_size = 128 << 20; // 128 MB
    a = (uint8_t *)aligned_alloc(32, data_size);
    if (!a) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        a[i] = (uint8_t)(i & 0xFF);
    }

    end_x = (int)(data_size - 1);
}