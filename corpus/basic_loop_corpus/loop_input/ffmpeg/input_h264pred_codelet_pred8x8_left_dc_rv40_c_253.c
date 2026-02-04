#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
ptrdiff_t stride;
int i;
unsigned int dc0;

static uint8_t *internal_src_buffer;
static uint32_t *row_pointers[8];

void init_vars() {
    const size_t data_size = 1 << 20;
    stride = 64;
    dc0 = 0xDEADBEEF;

    internal_src_buffer = aligned_alloc(64, data_size);
    if (!internal_src_buffer) {
        exit(1);
    }

    src = internal_src_buffer;

    for (int idx = 0; idx < 8; idx++) {
        uint8_t *row_base = src + idx * stride;
        uint32_t *as_uint32 = (uint32_t*)row_base;
        as_uint32[0] = 0;
        as_uint32[1] = 0;
    }
}