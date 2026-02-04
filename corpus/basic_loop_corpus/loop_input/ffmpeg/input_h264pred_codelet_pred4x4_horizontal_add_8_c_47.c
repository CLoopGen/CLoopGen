#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
uint8_t *pix;
int16_t *block;

static uint8_t *pix_buffer;
static int16_t *block_buffer;

void init_vars() {
    // Allocate sufficient data to make the loop take ~0.01 seconds
    // Each iteration processes 4 pixels and 4 coefficients, strides down
    // Aim for roughly 1M iterations to stay in typical range for modern CPUs
    const int num_iterations = 1 << 18;  // 262144 iterations

    // Allocate pix buffer: need at least (num_iterations * stride) bytes
    // Also ensure we can access pix[-1], so allocate extra byte at start
    stride = 16;  // reasonable stride, allows alignment
    size_t pix_size = num_iterations * stride + 16;
    pix_buffer = (uint8_t*)aligned_alloc(16, pix_size);
    if (!pix_buffer) exit(1);

    // Block needs 4 * num_iterations elements
    size_t block_size = num_iterations * 4;
    block_buffer = (int16_t*)aligned_alloc(16, block_size * sizeof(int16_t));
    if (!block_buffer) exit(1);

    // Initialize buffers to avoid undefined behavior
    for (size_t i = 0; i < pix_size; i++) {
        pix_buffer[i] = (uint8_t)(i & 0xFF);
    }
    for (size_t i = 0; i < block_size; i++) {
        block_buffer[i] = (int16_t)(i & 0x1FF) - 256;
    }

    // Set initial pointers
    pix = pix_buffer + 1;  // so pix[-1] is valid
    block = block_buffer;
}