#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *dst;
uint8_t *src;
int size;
int i;
int r;
int g;
int b;
int a;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate

    dst = (uint8_t*)aligned_alloc(32, data_size);
    src = (uint8_t*)aligned_alloc(32, data_size);

    if (!dst || !src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        src[idx] = (uint8_t)(idx % 251);
        dst[idx] = (uint8_t)((idx + 13) % 251);
    }

    size = (int)(data_size - 4); // Ensure i+3 is within bounds when i <= size-2
    i = 0;
    r = 100;
    g = 50;
    b = 25;
    a = 75;
}