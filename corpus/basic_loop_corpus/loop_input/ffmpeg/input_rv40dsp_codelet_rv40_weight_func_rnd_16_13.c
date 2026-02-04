#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB for sufficient runtime (~0.01 sec on modern CPU)

static uint8_t *dst_base;
static uint8_t *src1_base;
static uint8_t *src2_base;

uint8_t *dst;
uint8_t *src1;
uint8_t *src2;
int w1;
int w2;
ptrdiff_t stride;
int i;
int j;

void init_vars() {
    // Set parameters
    w1 = 123;
    w2 = 456;
    
    // Each iteration processes 16 bytes, and we do 16 rows
    // So we need at least 16*stride space, with each row having 16 valid elements
    // Choose stride to be a multiple of cache line size to avoid aliasing, minimum 32
    stride = 64; // bytes per row
    
    // Total buffer size: 16 rows * stride, plus some extra padding to prevent overflow
    size_t total_size = 16 * stride;
    
    // Allocate large enough buffers
    dst_base = (uint8_t*)aligned_alloc(64, DATA_SIZE);
    src1_base = (uint8_t*)aligned_alloc(64, DATA_SIZE);
    src2_base = (uint8_t*)aligned_alloc(64, DATA_SIZE);
    
    if (!dst_base || !src1_base || !src2_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    // Initialize with non-zero data to make computation meaningful
    for (size_t k = 0; k < DATA_SIZE; k++) {
        src1_base[k] = rand() & 0xFF;
        src2_base[k] = rand() & 0xFF;
        dst_base[k] = 0;
    }
    
    // Set working pointers to the beginning of usable regions
    src1 = src1_base;
    src2 = src2_base;
    dst = dst_base;
}

// Ensure cleanup is possible if needed (not required per spec but good practice)
void cleanup_vars() {
    free(dst_base);
    free(src1_base);
    free(src2_base);
}