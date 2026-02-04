#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int32_t dst_stride;
uint32_t row;

static uint8_t *dst_buffer;
static size_t total_size = 1 << 20; // 1MB for ~0.01 sec on modern CPU

void init_vars() {
    dst_stride = 64;
    dst_buffer = (uint8_t *)aligned_alloc(64, total_size);
    if (!dst_buffer) {
        exit(1);
    }
    dst = dst_buffer;
}

__attribute__((destructor))
static void cleanup() {
    free(dst_buffer);
}