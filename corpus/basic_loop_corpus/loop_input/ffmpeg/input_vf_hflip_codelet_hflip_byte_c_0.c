#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
int w;
int j;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU

    src_buffer = (uint8_t*)aligned_alloc(32, data_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, data_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        dst_buffer[i] = 0;
    }

    src = src_buffer + data_size - 1;
    dst = dst_buffer;
    w = data_size;
}