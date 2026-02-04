#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int x;
int size;
uint16_t *src;
uint16_t *top;
int dc;

uint16_t *src_data;
uint16_t *top_data;

void init_vars() {
    size = 64 * 1024 * 1024 / sizeof(uint16_t);
    stride = 1;
    dc = 42;

    src_data = aligned_alloc(32, (size + stride * (size)) * sizeof(uint16_t));
    top_data = aligned_alloc(32, size * sizeof(uint16_t));

    src = src_data;
    top = top_data;

    for (int i = 0; i < size; i++) {
        top[i] = i % 1024;
    }

    for (int i = 0; i < (size + stride * (size)); i++) {
        src_data[i] = 0;
    }
}