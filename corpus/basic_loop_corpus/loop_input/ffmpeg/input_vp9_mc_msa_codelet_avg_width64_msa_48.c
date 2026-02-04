#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
int32_t cnt;
uint8_t *dst_dup;

#define DATA_SIZE (128 << 20) // 128 MB of total data
#define BUFFER_PAD (16)

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static uint8_t *dst_dup_buffer;

void init_vars() {
    const int32_t block_height = 4;
    const int32_t pixel_size = 1; // bytes per pixel (uint8_t)

    // Choose stride and height such that we have reasonable memory access
    // Let's assume image width around 1920 for realistic stride, but scaled to touch ~128MB
    const int32_t width = 1920;
    src_stride = width * pixel_size;
    dst_stride = width * pixel_size;

    // Total number of blocks processed: height / 4
    // Each iteration processes 4 rows from src and writes 4 rows to dst/dst_dup
    // We want loop to run long enough to take ~0.01s -> aim for many iterations

    // Approximate total processed data: (height / 4) * 4 * width = height * width
    // Set total processed data to about 128MB
    const size_t total_pixels = DATA_SIZE;
    height = (total_pixels + width - 1) / width; // Ceiling divide
    // Round up so that total memory accessed is slightly over target

    // Ensure height is multiple of 4 for clean loop termination
    height = ((height + 3) / 4) * 4;

    const size_t buffer_size = (size_t)(height + BUFFER_PAD) * src_stride;

    // Allocate aligned buffers to avoid alignment issues
    src_buffer = (uint8_t*)aligned_alloc(32, buffer_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, buffer_size);
    dst_dup_buffer = (uint8_t*)aligned_alloc(32, buffer_size);

    if (!src_buffer || !dst_buffer || !dst_dup_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize buffers to zero (or any deterministic pattern)
    memset(src_buffer, 0x55, buffer_size);
    memset(dst_buffer, 0, buffer_size);
    memset(dst_dup_buffer, 0, buffer_size);

    // Initialize external pointers
    src = src_buffer + (BUFFER_PAD / 2) * src_stride;
    dst = dst_buffer + (BUFFER_PAD / 2) * dst_stride;
    dst_dup = dst_dup_buffer + (BUFFER_PAD / 2) * dst_stride;

    cnt = 0; // Will be set in loop, but initialize anyway
}