#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int h;
uint8_t *dst;
uint8_t *src;
int A;
int i;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    const size_t total_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate
    const int element_size = 2; // Two bytes accessed: index 0 and 1

    // Allocate large buffers to avoid out-of-bounds access
    dst_buffer = (uint8_t*)aligned_alloc(32, total_size);
    src_buffer = (uint8_t*)aligned_alloc(32, total_size);

    if (!dst_buffer || !src_buffer) {
        exit(1);
    }

    // Initialize buffer contents
    for (size_t idx = 0; idx < total_size; ++idx) {
        dst_buffer[idx] = (uint8_t)(idx % 256);
        src_buffer[idx] = (uint8_t)((idx * 3) % 256);
    }

    // Set stride to a reasonable value (e.g., width of a row in a pseudo 2D array)
    stride = 16; // Ensures multiple rows can be processed

    // Set height so that total memory accessed is within bounds
    // Each iteration advances by 'stride', and we access two elements per row
    h = (total_size / element_size) / stride;
    if (h > total_size / stride) h = total_size / stride;

    // Ensure h is positive and safe
    if (h <= 0) h = 1000;

    // Limit h to prevent overflow in pointer arithmetic
    size_t max_h = (total_size - element_size) / stride;
    if (h > max_h) h = max_h;

    // Initialize dst and src pointers to beginning of buffers
    dst = dst_buffer;
    src = src_buffer;

    // Initialize A to a meaningful value
    A = 42;

    // Initialize loop counter
    i = 0;
}