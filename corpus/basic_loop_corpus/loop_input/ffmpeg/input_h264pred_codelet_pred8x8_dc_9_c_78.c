#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

ptrdiff_t stride;
int i;
int dc0;
int dc1;
int dc2;
uint16_t *src;

void init_vars() {
    // Set reasonable stride to avoid overlapping too much; assume 2D-like access pattern
    stride = 1024;

    // Allocate a sufficiently large buffer to make loop take ~0.01s
    // Each iteration does 4 memory accesses, total 4 iterations => 16 accesses
    // To get measurable time, allocate enough data so that cache effects contribute
    size_t num_elements = 1 << 20; // 1M elements = 2MB (uint16_t is 2 bytes)
    src = (uint16_t*)aligned_alloc(32, sizeof(uint16_t) * num_elements);
    
    if (!src) {
        exit(1);
    }

    // Initialize all elements to prevent undefined behavior
    for (size_t idx = 0; idx < num_elements; ++idx) {
        src[idx] = (uint16_t)(idx % 65535);
    }

    // Ensure all array accesses in the loop are within bounds:
    // src[-1 + i * stride] for i in [0,3] -> indices: -1, -1+stride, -1+2*stride, -1+3*stride
    // src[i - stride] for i in [0,3] -> indices: -stride, -stride+1, -stride+2, -stride+3
    // src[4 + i - stride] for i in [0,3] -> indices: 4-stride to 7-stride
    // src[-1 + (i+4)*stride] for i in [0,3] -> indices: -1+4*stride to -1+7*stride

    // The most negative index is min(-1, -stride) = -stride (when stride > 1)
    // The most positive index is max(-1+3*stride, 7-stride, -1+7*stride) ≈ 7*stride
    // So we require: -stride >= 0 offset? No — we need base pointer shifted forward.

    // Shift base pointer so that negative indices are valid
    // We need at least 'stride' elements before logical start
    uint16_t* logical_start = src + stride;
    
    // But some expressions go up to -1 + 7*stride, so we need at least 7*stride + 1 elements after logical start
    size_t required_buffer_size = 8 * stride + 1;
    if (required_buffer_size > num_elements) {
        free(src);
        src = (uint16_t*)aligned_alloc(32, sizeof(uint16_t) * required_buffer_size);
        if (!src) {
            exit(1);
        }
        for (size_t idx = 0; idx < required_buffer_size; ++idx) {
            src[idx] = (uint16_t)(idx % 65535);
        }
        logical_start = src + stride;
    }

    src = logical_start;

    // Reset accumulators
    dc0 = 0;
    dc1 = 0;
    dc2 = 0;
}