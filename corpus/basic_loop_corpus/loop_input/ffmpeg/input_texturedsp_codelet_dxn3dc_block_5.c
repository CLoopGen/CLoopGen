#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t stride;
int x;
int y;

static uint8_t *internal_dst;
static ptrdiff_t internal_stride;

void init_vars() {
    const int width = 4;
    const int height = 4;
    internal_stride = width * sizeof(uint8_t);
    size_t total_size = (size_t)height * (size_t)internal_stride;

    internal_dst = aligned_alloc(32, total_size);
    if (!internal_dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        internal_dst[i] = (uint8_t)(i & 0xFF);
    }

    dst = internal_dst;
    stride = internal_stride;
}