#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

ptrdiff_t stride;
int size;
int x;
int y;
uint8_t *src;
int angle;
uint8_t *ref;

#define DATA_SIZE_MB 64
#define TOTAL_BYTES (DATA_SIZE_MB * 1024 * 1024)

static uint8_t *src_buffer;
static uint8_t *ref_buffer;

void init_vars() {
    size = 256;  // Block size for the loop
    stride = size;  // Assume row stride equals block width
    angle = 192;   // Arbitrary valid angle value that ensures idx stays within bounds

    // Allocate buffers with padding to prevent out-of-bounds access
    // Maximum index into ref: x + idx + 2, where x < size, idx <= (size * angle) >> 5
    int max_idx = ((size) * angle) >> 5;
    int ref_needed = size + max_idx + 3;  // Add extra padding for safety

    src_buffer = (uint8_t*)aligned_alloc(32, TOTAL_BYTES);
    ref_buffer = (uint8_t*)aligned_alloc(32, ref_needed);

    if (!src_buffer || !ref_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = src_buffer;
    ref = ref_buffer;

    // Initialize arrays to avoid undefined behavior
    for (int i = 0; i < size * size; i++) {
        src_buffer[i] = i & 0xFF;
    }
    for (int i = 0; i < ref_needed; i++) {
        ref_buffer[i] = (i * 37) & 0xFF;
    }

    // Ensure x and y are initialized to safe values (will be overwritten in loop)
    x = 0;
    y = 0;
}