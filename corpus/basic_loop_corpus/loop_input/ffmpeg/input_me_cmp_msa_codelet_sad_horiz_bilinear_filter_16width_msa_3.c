#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *src;
int32_t src_stride;
uint8_t *ref;
int32_t ref_stride;
int32_t height;
int32_t ht_cnt;

static uint8_t *src_data;
static uint8_t *ref_data;

void init_vars() {
    // Aim for approximately 64MB of total data to target ~0.01s runtime
    const int32_t total_size = 1 << 26; // ~64MB
    const int32_t block_height = 1 << 10; // 1024 rows
    const int32_t block_width = total_size / block_height;
    
    // Ensure dimensions are multiples of 8 and 4 for safe loop operation
    src_stride = ((block_width + 7) / 8) * 8;
    ref_stride = ((block_width + 7) / 8) * 8;
    
    height = block_height & ~7; // Make sure height is multiple of 8
    
    // Allocate memory with padding for safe access
    src_data = aligned_alloc(32, (size_t)height * src_stride);
    ref_data = aligned_alloc(32, (size_t)height * ref_stride);
    
    if (!src_data || !ref_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    // Initialize with predictable patterns
    for (int i = 0; i < height * src_stride; i++) {
        src_data[i] = (uint8_t)(i % 251);
    }
    for (int i = 0; i < height * ref_stride; i++) {
        ref_data[i] = (uint8_t)((i * 37) % 199);
    }
    
    // Set pointers to middle of data to allow offset arithmetic in loop
    src = src_data + (src_stride * (height / 4));
    ref = ref_data + (ref_stride * (height / 4));
    
    // Adjust height so that ht_cnt = height >> 3 allows full traversal without OOB
    height = (height / 2) & ~7;
}