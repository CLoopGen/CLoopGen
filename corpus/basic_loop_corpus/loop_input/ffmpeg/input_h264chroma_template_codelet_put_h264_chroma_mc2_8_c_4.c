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
int E;
ptrdiff_t step;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;
static size_t total_size;

void init_vars() {
    // Set parameters for ~0.01s runtime: use ~16-64MB of data based on typical CPU speed
    total_size = 32 * 1024 * 1024; // 32 MB
    h = 8192; // Number of iterations
    stride = 4096; // Stride in bytes (simulates row size)
    step = 1; // Offset step within the row

    // Ensure we don't exceed buffer bounds: each iteration accesses up to [step + 1]
    if ((size_t)(h * stride) + step + 1 >= total_size) {
        total_size = (h * stride) + step + 1 + 4096;
    }

    // Allocate buffers with sufficient space
    dst_buffer = aligned_alloc(32, total_size);
    src_buffer = aligned_alloc(32, total_size);

    // Initialize pointers
    dst = dst_buffer;
    src = src_buffer;

    // Initialize coefficients
    A = 17;
    E = 23;

    // Initialize input data
    for (size_t idx = 0; idx < total_size; idx++) {
        src_buffer[idx] = (uint8_t)(idx % 251);
    }
}