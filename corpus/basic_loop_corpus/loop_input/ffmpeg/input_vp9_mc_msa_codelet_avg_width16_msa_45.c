#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
int32_t cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    size_t total_size = 64 * 1024 * 1024; // 64 MB for substantial workload (~0.01 sec estimate)
    src_stride = 2048; // Simulate a wide image stride
    dst_stride = 2048;
    height = (total_size / src_stride) & ~3; // Ensure divisible by 4

    if (height == 0) height = 4;

    src_buffer = aligned_alloc(32, total_size);
    dst_buffer = aligned_alloc(32, total_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = src_buffer;
    dst = dst_buffer;

    cnt = 0;
}

__attribute__((destructor))
static void cleanup() {
    free(src_buffer);
    free(dst_buffer);
}