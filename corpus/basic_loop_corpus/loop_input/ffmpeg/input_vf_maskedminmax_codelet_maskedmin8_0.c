#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
uint8_t *f1;
uint8_t *f2;
int w;

static size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime

void init_vars() {
    w = (int)(data_size / sizeof(uint8_t));

    src = (uint8_t *)aligned_alloc(32, data_size);
    dst = (uint8_t *)aligned_alloc(32, data_size);
    f1 = (uint8_t *)aligned_alloc(32, data_size);
    f2 = (uint8_t *)aligned_alloc(32, data_size);

    for (size_t i = 0; i < data_size; i++) {
        src[i] = rand() % 256;
        f1[i] = rand() % 256;
        f2[i] = rand() % 256;
        dst[i] = 0;
    }
}