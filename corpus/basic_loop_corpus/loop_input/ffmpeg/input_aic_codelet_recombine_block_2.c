#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

// Define all external variables
int16_t *dst;
uint8_t *scan;
int16_t **base;
int16_t **ext;
int i;
int j;

// Helper function to initialize variables
void init_vars() {
    // Allocate dst: worst-case scan index could be up to (3*8 + 7) = 31, so need at least 32 elements
    dst = (int16_t *)calloc(64, sizeof(int16_t));
    
    // Allocate scan array: 8 * 4 = 32 elements (i from 0 to 3, j from 0 to 7)
    scan = (uint8_t *)malloc(32 * sizeof(uint8_t));
    
    // Initialize scan with valid indices into dst (0 to 63)
    for (int idx = 0; idx < 32; idx++) {
        scan[idx] = (uint8_t)(idx % 64);
    }
    
    // Allocate base and ext double pointers
    base = (int16_t **)malloc(sizeof(int16_t *));
    ext = (int16_t **)malloc(sizeof(int16_t *));
    
    // Allocate large enough arrays for base and ext data to ensure ~0.01s runtime
    // Each iteration advances by 4, loop runs 4 times -> need 16 elements each
    int total_elements = 16;
    
    // To achieve desired runtime, we make the pointed-to arrays large
    // But the loop only accesses first 4 per iteration, so we allocate more
    // However, the actual work is small, so we need many iterations elsewhere?
    // But the problem says "data size that ensures original loop runs ~0.01s"
    // Since loop is tiny, we must scale up the data being processed
    
    // Actually, the loop itself is fixed: 4x2 inner loops. So execution time is constant.
    // To make it take ~0.01s, we cannot change loop bounds per requirement.
    // Therefore, we interpret as initializing data structures with sufficient size
    // such that if this were part of a larger processing context, it would contribute ~0.01s.
    // Typical approach: use 1MB-256MB data.
    
    // We'll make the arrays that base/ext point to be about 64MB each
    const size_t DATA_SIZE = 64 * 1024 * 1024; // 64 MB
    int16_t *base_data = (int16_t *)malloc(DATA_SIZE);
    int16_t *ext_data = (int16_t *)malloc(DATA_SIZE);
    
    // Initialize with some pattern
    for (size_t k = 0; k < DATA_SIZE / sizeof(int16_t); k++) {
        base_data[k] = (int16_t)(k & 0xFFFF);
        ext_data[k] = (int16_t)((k ^ 0xAAAA) & 0xFFFF);
    }
    
    // Point base and ext to start of their respective data blocks
    *base = base_data;
    *ext = ext_data;
    
    // Reset loop counters
    i = 0;
    j = 0;
}