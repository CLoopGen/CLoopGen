#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
uint8_t *top;
int bpp;
int i;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;
static uint8_t *top_buffer;

void init_vars() {
    size_t data_size = 128 << 20; // 128 MB

    dst_buffer = aligned_alloc(32, data_size);
    src_buffer = aligned_alloc(32, data_size);
    top_buffer = aligned_alloc(32, data_size);

    dst = dst_buffer;
    src = src_buffer;
    top = top_buffer;

    bpp = (int)(data_size / 4); // Ensure bpp is large enough but within bounds

    for (size_t j = 0; j < data_size; j++) {
        src_buffer[j] = (uint8_t)(rand() & 0xFF);
        top_buffer[j] = (uint8_t)(rand() & 0xFF);
    }
}