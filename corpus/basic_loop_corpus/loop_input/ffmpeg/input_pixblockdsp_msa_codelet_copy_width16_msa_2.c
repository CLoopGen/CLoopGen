#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
int32_t cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    // Aim for ~100ms execution: use block count and size to derive total data
    // The loop processes 12 rows per iteration (height / 12), each "step" moves by 8 + 4 = 12 in src/dst vertically
    // Assume we want around 64MB of processed data to get measurable time (~0.01-0.1s)

    const int block_height = 12;
    const int block_width = 64; // arbitrary width, chosen for reasonable memory access

    // Total number of iterations: let's target about 1M blocks -> 12M rows
    // But limit memory to ~64-128MB range
    const int total_blocks = 1 << 16; // 65536 blocks
    height = total_blocks * block_height; // 786432 rows

    src_stride = block_width + 16; // add padding to prevent false sharing
    dst_stride = block_width + 16;

    size_t src_size = (size_t)height * (size_t)src_stride;
    size_t dst_size = (size_t)height * (size_t)dst_stride;

    // Allocate buffers with calloc to ensure zeroed memory
    src_buffer = (uint8_t*)calloc(1, src_size);
    dst_buffer = (uint8_t*)calloc(1, dst_size);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Failed to allocate buffers\n");
        exit(1);
    }

    // Initialize src with non-zero pattern to allow correctness inspection
    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }

    // Set pointers
    src = src_buffer;
    dst = dst_buffer;

    // Initialize other variables
    cnt = 0; // will be set in loop: cnt = height / 12
}