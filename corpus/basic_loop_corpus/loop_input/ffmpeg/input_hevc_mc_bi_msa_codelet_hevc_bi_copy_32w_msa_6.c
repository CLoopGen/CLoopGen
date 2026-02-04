#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *src0_ptr;
int32_t src_stride;
int16_t *src1_ptr;
int32_t src2_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
uint32_t loop_cnt;

static uint8_t *src0_base;
static int16_t *src1_base;
static uint8_t *dst_base;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB per buffer for sufficient workload
    const int alignment = 64;

    // Allocate aligned memory to prevent cache effects and ensure safety
    src0_base = aligned_alloc(alignment, data_size);
    src1_base = aligned_alloc(alignment, data_size);
    dst_base = aligned_alloc(alignment, data_size);

    // Initialize buffers with predictable patterns
    for (size_t i = 0; i < data_size; ++i) {
        src0_base[i] = (uint8_t)(i & 0xFF);
        if (i < data_size / sizeof(int16_t)) {
            ((int16_t*)src1_base)[i] = (int16_t)(i & 0x7FFF);
        }
        dst_base[i] = 0;
    }

    // Set up parameters to ensure no out-of-bounds access
    src_stride = 64;         // reasonable step in bytes
    src2_stride = 32;        // stride in units of int16_t* (so 32 * sizeof(int16_t) bytes)
    dst_stride = 128;

    // Each iteration advances src0_ptr by src_stride twice => total 2*src_stride per loop
    // We require: (height >> 1) iterations, so total advance = (height >> 1) * 2 * src_stride
    // Ensure that src0_ptr does not exceed allocated bounds
    // Max offset = (height >> 1) * 2 * src_stride <= data_size - initial_offset
    // Assume starting at beginning: choose height so that total advance is <= data_size

    int max_iterations = data_size / (2 * src_stride);
    height = max_iterations << 1;  // ensures loop_cnt = height >> 1 = max_iterations

    // Cap height to avoid overflow or excessive values
    if (height <= 0 || height > (int32_t)data_size) {
        height = (data_size / (2 * src_stride)) << 1;
    }

    // Initialize pointers
    src0_ptr = src0_base;
    src1_ptr = src1_base;
    dst = dst_base;

    loop_cnt = 0;
}

// Ensure cleanup if needed (not called here but allocation is valid for process lifetime)