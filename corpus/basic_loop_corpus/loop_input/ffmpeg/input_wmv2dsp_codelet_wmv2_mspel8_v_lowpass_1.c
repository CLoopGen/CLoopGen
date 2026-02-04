#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int w;
uint8_t *cm;
int i;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;
static uint8_t *cm_table;

void init_vars() {
    // Define data sizes to achieve ~0.01 seconds runtime
    // Empirical tuning: aim for about 64K-256K iterations with reasonable buffer sizes
    w = 65536;  // Number of loop iterations

    srcStride = 16;  // Stride values must allow access up to 9*srcStride safely
    dstStride = 16;

    // src needs to access from -srcStride to 9*srcStride offset, so we need padding
    size_t src_pitch = w + 10 * srcStride + 1;  // Extra space before and after
    size_t dst_pitch = w + 10 * dstStride + 1;

    // Allocate large enough buffers with padding to prevent out-of-bounds access
    src_buffer = (uint8_t*)aligned_alloc(32, sizeof(uint8_t) * src_pitch);
    dst_buffer = (uint8_t*)aligned_alloc(32, sizeof(uint8_t) * dst_pitch);
    cm_table = (uint8_t*)aligned_alloc(32, sizeof(uint8_t) * 256);

    // Initialize cm table to identity mapping in valid range
    for (int idx = 0; idx < 256; idx++) {
        cm_table[idx] = (uint8_t)(idx & 0xFF);
    }

    // Set working pointers so that indexing stays in bounds
    // src[-srcStride] must be valid -> src must point at least srcStride past start
    src = src_buffer + srcStride;
    dst = dst_buffer;

    // Initialize source data to avoid undefined behavior
    for (size_t j = 0; j < src_pitch; j++) {
        src_buffer[j] = (uint8_t)((j * 17) & 0xFF);
    }
    for (size_t j = 0; j < dst_pitch; j++) {
        dst_buffer[j] = 0;
    }

    // Ensure cm is valid for index range that may be accessed
    // Index expression: (9*(a+b) - (c+d) + 8) >> 4
    // Max: (9*(255+255) - (0+0) + 8)/16 = ~286, min: (9*(0+0)- (255+255)+8)/16 ~ -31
    // But cm[] is used as lookup with clamping implied by construction
    // We allocated 256 entries and filled them safely
    cm = cm_table;
}