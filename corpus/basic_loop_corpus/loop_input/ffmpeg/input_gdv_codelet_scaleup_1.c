#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int w;
int x;

static uint8_t *internal_src;
static uint8_t *internal_dst;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate
    internal_src = (uint8_t *)aligned_alloc(32, data_size);
    internal_dst = (uint8_t *)aligned_alloc(32, data_size);
    
    if (!internal_src || !internal_dst) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        internal_src[i] = (uint8_t)(i & 0xFF);
        internal_dst[i] = 0;
    }

    src = internal_src;
    dst = internal_dst;
    w = (int)(data_size - 8); // ensures x < w-7 is valid and avoids out-of-bounds
}