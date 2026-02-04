#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int w;
int x;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    size_t data_size = 128 << 20; // 128 MB

    src_buffer = aligned_alloc(32, data_size);
    dst_buffer = aligned_alloc(32, data_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }

    dst = dst_buffer;
    src = src_buffer;
    w = (int)(data_size / 2); 
    x = 0;
}