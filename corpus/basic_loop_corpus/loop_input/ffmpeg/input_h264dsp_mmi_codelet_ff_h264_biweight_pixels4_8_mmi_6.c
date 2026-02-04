#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
int height;
int y;

#define DATA_SIZE (128 << 20) // 128 MB

static uint8_t *internal_dst_buffer;
static uint8_t *internal_src_buffer;

void init_vars() {
    internal_dst_buffer = (uint8_t *)aligned_alloc(32, DATA_SIZE);
    internal_src_buffer = (uint8_t *)aligned_alloc(32, DATA_SIZE);

    if (!internal_dst_buffer || !internal_src_buffer) {
        exit(1);
    }

    stride = 64; 
    height = DATA_SIZE / stride;

    dst = internal_dst_buffer;
    src = internal_src_buffer;
}