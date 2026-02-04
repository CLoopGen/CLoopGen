#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t dstStride;
ptrdiff_t srcStride;
int w;
uint8_t *cm;
int i;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;
static uint8_t cm_buffer[256];

void init_vars() {
    // Set constants
    dstStride = 1;
    srcStride = 1;
    w = 100000;  // Adjusted for ~0.01s runtime

    // Allocate cm (used as lookup table with byte index)
    cm = cm_buffer;
    for (int i = 0; i < 256; i++) {
        cm[i] = (uint8_t)(i & 0xFF);
    }

    // Allocate source and destination buffers with padding to prevent out-of-bounds access
    // We access src[-2*srcStride] up to src[10*srcStride], so we need at least 12 extra elements before/after?
    // But since we use src[-2] to src[10], we need src to have at least 13 elements including base
    // However, we also increment src and dst in the loop, so we must account for all iterations.

    // Total src offset range: from -2 to 10 + (w-1)*1 => max index = w + 9
    // So total required size = w + 11 (to cover -2..w+9 inclusive)
    size_t src_size = w + 12;
    src_buffer = (uint8_t*)calloc(src_size, sizeof(uint8_t));
    if (!src_buffer) exit(1);

    // Similarly, dst is accessed from 0 to 7 per iteration, and we write up to dst[7*dstStride]
    // And dst is incremented each time -> max offset = 7 + (w-1) = w + 6
    size_t dst_size = w + 8;
    dst_buffer = (uint8_t*)calloc(dst_size, sizeof(uint8_t));
    if (!dst_buffer) exit(1);

    // Initialize src and dst base pointers to point after the initial offset
    // We want src[-2] to be valid -> src must start at index >= 2
    src = src_buffer + 2;
    dst = dst_buffer;

    // Initialize src data to avoid undefined behavior in computation
    for (size_t idx = 0; idx < src_size; idx++) {
        src_buffer[idx] = rand() & 0xFF;
    }
    for (size_t idx = 0; idx < dst_size; idx++) {
        dst_buffer[idx] = rand() & 0xFF;
    }
}