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
static size_t total_size = 1 << 20; // 1MB data size

void init_vars() {
    src_buffer = (uint8_t*)calloc(total_size, sizeof(uint8_t));
    dst_buffer = (uint8_t*)calloc(total_size, sizeof(uint8_t));

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    src = src_buffer + (8 + 8 + 1) + 1; // Offset to allow access from base with y+x up to 7+7
    dst = dst_buffer;
    stride = 8; // Each row advances dst by 8 bytes

    for (size_t i = 0; i < total_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
}