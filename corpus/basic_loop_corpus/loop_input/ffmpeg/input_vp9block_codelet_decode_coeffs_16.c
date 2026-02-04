#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int end_x;
int n;
uint8_t *a;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime
    a = (uint8_t*)aligned_alloc(32, data_size);
    if (!a) {
        exit(1);
    }
    for (size_t i = 0; i < data_size; ++i) {
        a[i] = (uint8_t)(i & 0xFF);
    }
    end_x = data_size - 4; // Ensure n+3 < data_size when accessing a[n], and n-1 valid when n=1
}