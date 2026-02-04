#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
int32_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static int32_t data_size;

void init_vars() {
    data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate

    src_buffer = (uint8_t*)aligned_alloc(32, data_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, data_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize buffer contents to avoid undefined behavior
    for (int i = 0; i < data_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        dst_buffer[i] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;

    src_stride = 1024;
    dst_stride = 1024;

    height = (data_size / src_stride) & ~1; // Ensure even number of rows
}

// Ensure symbols are defined and can be linked
__attribute__((destructor))
static void cleanup() {
    free(src_buffer);
    free(dst_buffer);
}