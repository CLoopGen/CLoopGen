#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
int h;
int A;
int B;
int C;
int D;
int i;
int bias;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;

void init_vars() {
    // Define constants for data size
    const int width = 1024;  // Number of bytes per row
    h = 65536 / width;       // Total rows to get ~64k elements, adjust for ~0.01s runtime
    if (h < 1) h = 1;
    stride = width + 32;     // Add padding to prevent overflow on stride accesses

    // Allocate buffers with sufficient size, accounting for maximum index used:
    // src[stride + 4] is max accessed -> need at least (h * stride) + stride + 5 bytes
    size_t buffer_size = (h + 2) * stride + 8;
    dst_buffer = (uint8_t*)aligned_alloc(32, buffer_size);
    src_buffer = (uint8_t*)aligned_alloc(32, buffer_size);

    // Initialize pointers
    dst = dst_buffer + 16;
    src = src_buffer + 16;

    // Initialize coefficients and bias
    A = 17;
    B = -9;
    C = 23;
    D = -7;
    bias = 32;  // >>6 will have rounding effect

    // Initialize src and dst memory to non-zero predictable values
    for (size_t idx = 0; idx < buffer_size; idx++) {
        src_buffer[idx] = (uint8_t)(idx & 0xFF);
        dst_buffer[idx] = (uint8_t)((idx * 3) & 0xFF);
    }

    i = 0;
}