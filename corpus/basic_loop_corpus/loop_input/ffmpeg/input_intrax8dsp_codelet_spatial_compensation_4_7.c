#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
ptrdiff_t stride;
int x;
int y;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t total_data_size = 16 * 1024 * 1024;

void init_vars() {
    src_buffer = (uint8_t*)aligned_alloc(32, total_data_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, total_data_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < total_data_size; i++) {
        src_buffer[i] = rand() & 0xFF;
        dst_buffer[i] = 0;
    }

    src = src_buffer + (8 + 8 + 1); 
    dst = dst_buffer;
    stride = 8;
}