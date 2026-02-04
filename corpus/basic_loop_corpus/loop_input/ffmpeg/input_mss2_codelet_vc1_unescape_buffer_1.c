#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int size;
uint8_t *dst;
int dsize;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t data_size = 1 << 20; // 1MB for ~0.01s runtime

void init_vars() {
    src_buffer = (uint8_t*)malloc(data_size);
    dst_buffer = (uint8_t*)malloc(data_size);
    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }

    src = src_buffer;
    dst = dst_buffer;
    size = data_size;
    dsize = 0;
}