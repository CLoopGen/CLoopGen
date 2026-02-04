#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
uint8_t *iv;
int i;

static uint8_t *alloc_aligned(size_t size) {
    void *ptr;
    if (posix_memalign(&ptr, 32, size) != 0) {
        return NULL;
    }
    return (uint8_t *)ptr;
}

void init_vars() {
    size_t total_size = 16777216; // 16MB for ~0.01s runtime on modern CPU

    dst = alloc_aligned(total_size);
    src = alloc_aligned(total_size);
    iv  = alloc_aligned(total_size);

    for (size_t j = 0; j < total_size; j++) {
        src[j] = (uint8_t)(j & 0xFF);
        iv[j]  = (uint8_t)((j ^ 0xAA) & 0xFF);
    }

    i = 0;
}