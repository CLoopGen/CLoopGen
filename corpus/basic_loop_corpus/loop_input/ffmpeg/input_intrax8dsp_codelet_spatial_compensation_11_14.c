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
static size_t total_size = 1 << 20; // 1MB for ~0.01s runtime estimate

void init_vars() {
    src_buffer = (uint8_t*)calloc(total_size, sizeof(uint8_t));
    dst_buffer = (uint8_t*)calloc(total_size, sizeof(uint8_t));
    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        src_buffer[i] = rand() & 0xFF;
    }

    src = src_buffer;
    dst = dst_buffer;
    stride = 8;
}