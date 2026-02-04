#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int end_y;
int n;
uint8_t *l;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate
    l = (uint8_t*)aligned_alloc(32, data_size);
    if (!l) {
        exit(1);
    }
    for (size_t i = 0; i < data_size; ++i) {
        l[i] = (uint8_t)(i & 0xFF);
    }
    end_y = (int)(data_size - 4); // Ensure n+4 doesn't go out of bounds
}