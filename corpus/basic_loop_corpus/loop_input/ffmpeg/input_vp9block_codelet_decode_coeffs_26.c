#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int end_x;
int n;
uint8_t *a;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    a = aligned_alloc(32, data_size);
    if (!a) {
        exit(1);
    }
    end_x = data_size - (data_size % 8) - 1; // Ensure n + 8 stays within bounds and aligns with loop increment
    for (size_t i = 0; i < data_size; ++i) {
        a[i] = (uint8_t)(i & 0xFF);
    }
}