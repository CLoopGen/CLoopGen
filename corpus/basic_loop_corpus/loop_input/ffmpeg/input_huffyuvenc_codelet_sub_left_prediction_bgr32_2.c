#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int i;
int r;
int g;
int b;
int a;
int min_width;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate
    src = (uint8_t*)aligned_alloc(32, data_size);
    dst = (uint8_t*)aligned_alloc(32, data_size);

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        src[idx] = rand() % 256;
    }

    min_width = (data_size / 4) - 1;

    r = src[2];
    g = src[1];
    b = src[0];
    a = src[3];
}