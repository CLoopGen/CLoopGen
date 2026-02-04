#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int x;
int size;
uint8_t *src;
uint8_t *top;
int dc;

uint8_t *src_data;
uint8_t *top_data;

void init_vars() {
    size = 64 * 1024 * 1024; // 64 million elements for ~0.01 sec runtime
    stride = 1;
    dc = 42;

    src_data = aligned_alloc(32, size * stride * sizeof(uint8_t));
    top_data = aligned_alloc(32, size * sizeof(uint8_t));

    if (!src_data || !top_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = src_data;
    top = top_data;

    for (int i = 0; i < size; i++) {
        top[i] = (uint8_t)(i & 0xFF);
    }
}