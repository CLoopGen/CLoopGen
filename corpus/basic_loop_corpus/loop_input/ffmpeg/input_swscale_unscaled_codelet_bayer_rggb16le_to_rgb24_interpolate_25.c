#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};

uint8_t *src;
int src_stride;
uint8_t *dst;
int dst_stride;
int width;
int i;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t total_src_size;
static size_t total_dst_size;

void init_vars() {
    // Set dimensions to achieve ~0.01s runtime
    // Based on typical performance, width around 8000-16000 gives reasonable timing
    width = 8192;
    int height = 8192;
    
    src_stride = width * 2; // Assuming 2 bytes per pixel due to unaligned_16 access
    dst_stride = width * 3; // Assuming 3 bytes per pixel in output
    
    total_src_size = (size_t)(height + 4) * src_stride; // Add border padding
    total_dst_size = (size_t)(height + 2) * dst_stride;
    
    // Allocate buffers with padding to avoid out-of-bounds access
    src_buffer = (uint8_t*)aligned_alloc(32, total_src_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, total_dst_size);
    
    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    // Initialize source data to non-zero values for meaningful computation
    for (size_t idx = 0; idx < total_src_size; idx++) {
        src_buffer[idx] = (uint8_t)(idx % 251);
    }
    
    // Clear destination
    for (size_t idx = 0; idx < total_dst_size; idx++) {
        dst_buffer[idx] = 0;
    }
    
    // Initialize pointers
    src = src_buffer + (2 * src_stride) + 4; // Centered to allow [-1,+1] row and [-1,+1] col offsets with 2-byte loads
    dst = dst_buffer + dst_stride + 3;      // Allow output at (0,0) as center of processing block
    
    // Adjust width to ensure loop bounds are safe: i < width - 2, and we step by 2
    // Ensure that maximum accessed src index stays within allocated bounds
    width = width - 4; // Reserve border margin for stencil accesses
}