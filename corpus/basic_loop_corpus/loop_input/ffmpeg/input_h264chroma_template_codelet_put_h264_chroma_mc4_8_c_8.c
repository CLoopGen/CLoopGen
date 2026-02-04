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
static ptrdiff_t buffer_stride;

void init_vars() {
    // Set A to a reasonable constant value
    A = 42;

    // Define approximate target execution time and data size
    // Aim for around 100 million operations to take ~0.01s on modern CPU
    // Each loop iteration processes 4 elements, so set h accordingly
    h = 25000000;  // 25M iterations -> ~100M operations

    // Stride in bytes: assume we're processing byte arrays with stride >= 4
    buffer_stride = 64;  // Use 64-byte aligned stride for cache efficiency
    stride = buffer_stride;

    // Allocate buffers with enough space: h rows of at least 4 bytes each, plus padding
    size_t total_size = (size_t)h * (size_t)buffer_stride;

    if ((dst_buffer = aligned_alloc(64, total_size)) == NULL) abort();
    if ((src_buffer = aligned_alloc(64, total_size)) == NULL) abort();

    dst = dst_buffer;
    src = src_buffer;

    // Initialize src data to non-zero values for meaningful computation
    for (size_t idx = 0; idx < total_size; idx++) {
        src_buffer[idx] = (uint8_t)(idx % 256);
    }

    // Clear destination
    for (size_t idx = 0; idx < total_size; idx++) {
        dst_buffer[idx] = 0;
    }
}