#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int x;

static uint8_t *internal_dst;
static uint8_t *internal_src;
static size_t data_size;

void init_vars() {
    data_size = 1 << 20; // 1 MB of data

    internal_src = (uint8_t*)aligned_alloc(32, data_size);
    internal_dst = (uint8_t*)aligned_alloc(32, data_size);

    if (!internal_src || !internal_dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        internal_src[i] = (uint8_t)(i & 0xFF);
        internal_dst[i] = 0;
    }

    dst = internal_dst + 7; // Adjust so that x starts at a valid offset
    src = internal_src;
    x = (int)(data_size - 8); // Ensure loop runs with valid bounds: x >= 0 and aligned to step by 8
}