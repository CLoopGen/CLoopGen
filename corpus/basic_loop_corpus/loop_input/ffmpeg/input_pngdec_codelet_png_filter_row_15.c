#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
uint8_t *last;
int size;
int i;
int r;
int g;
int b;
int a;

static uint8_t *alloc_aligned(size_t size) {
    void *ptr;
    if (posix_memalign(&ptr, 32, size) != 0) {
        return NULL;
    }
    return (uint8_t *)ptr;
}

void init_vars() {
    size = 64 * 1024 * 1024;
    dst = alloc_aligned(size);
    src = alloc_aligned(size);
    last = alloc_aligned(size);

    if (!dst || !src || !last) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < size; ++j) {
        src[j] = rand() & 255;
        last[j] = rand() & 255;
    }

    i = 0;
    r = rand() & 255;
    g = rand() & 255;
    b = rand() & 255;
    a = rand() & 255;
}