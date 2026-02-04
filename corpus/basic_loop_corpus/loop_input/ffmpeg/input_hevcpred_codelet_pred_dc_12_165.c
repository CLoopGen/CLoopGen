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

uint16_t *src_buf;
uint16_t *top_buf;

void init_vars() {
    size = 64 * 1024 * 1024; // 64M elements to target ~0.01s runtime
    stride = size;

    src_buf = aligned_alloc(32, (size + stride * 1) * sizeof(uint16_t));
    top_buf = aligned_alloc(32, size * sizeof(uint16_t));

    if (!src_buf || !top_buf) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = src_buf;
    top = top_buf;

    for (int i = 0; i < size; i++) {
        top[i] = (uint16_t)(i & 0xFFFF);
    }

    dc = 1234;

    x = 0;
}