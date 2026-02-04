#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
int src_size;
int i;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t total_src_size;
static size_t total_dst_size;

void init_vars() {
    total_src_size = 192 * 1024 * 1024; // 192 MB to target ~0.01 sec on modern CPU
    total_dst_size = (total_src_size / 3) * 4;

    src_buffer = (uint8_t*)aligned_alloc(32, total_src_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, total_dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_src_size; ++idx) {
        src_buffer[idx] = (uint8_t)(idx % 256);
    }
    for (size_t idx = 0; idx < total_dst_size; ++idx) {
        dst_buffer[idx] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
    src_size = total_src_size;
    i = 0;
}