#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int end_y;
int n;
uint8_t *l;

void init_vars() {
    size_t data_size = 128 << 20; // 128 MB
    l = aligned_alloc(32, data_size);
    if (!l) {
        exit(1);
    }
    end_y = data_size - (data_size % 8); // Ensure end_y is multiple of 8 and within bounds
    for (size_t i = 0; i < data_size; ++i) {
        l[i] = (uint8_t)(i & 0xFF);
    }
}