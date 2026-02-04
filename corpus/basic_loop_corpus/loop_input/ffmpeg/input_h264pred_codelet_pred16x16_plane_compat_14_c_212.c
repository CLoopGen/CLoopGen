#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int k;
int stride;
uint16_t * src0;
uint16_t * src1;
uint16_t * src2;
int H;
int V;

static uint16_t *buffer = NULL;
static size_t buffer_size = 0;

void init_vars() {
    // Aim for ~100ms execution - use large enough data to make loop overhead measurable
    // The loop runs 7 iterations (k=2..8), so we need to ensure memory accesses are valid
    
    // Minimum safe buffer padding: access at index -k and +k -> need at least 9 elements before/after center
    const int margin = 9;
    const int total_size = 1024 * 1024 / sizeof(uint16_t); // ~1MB of data
    buffer_size = total_size;
    
    // Allocate large buffer
    buffer = (uint16_t*)aligned_alloc(64, buffer_size * sizeof(uint16_t));
    if (!buffer) {
        exit(1);
    }
    memset(buffer, 0, buffer_size * sizeof(uint16_t));
    
    // Initialize random data for interesting computation
    srand((unsigned int)(time(NULL) ^ (uintptr_t)&buffer));
    for (size_t i = 0; i < buffer_size; ++i) {
        buffer[i] = (uint16_t)(rand() & 0xFFFF);
    }
    
    // Set up pointers so all array accesses in loop stay in bounds
    // We require: src0[-k] and src0[k] for k=2..8 => need at least index range [-8,8]
    // So place usable src0 starting at offset >=8
    size_t center = margin;
    if (center + 9 >= buffer_size) {
        center = buffer_size / 2;
    }
    
    src0 = buffer + center;
    
    // For src1 and src2: accessed at [0] after shifting by stride
    // Need to ensure they remain within bounds during all iterations
    stride = 1; // Small stride to avoid overflow
    
    // Allocate region for src1 and src2 such that adding/subtracting stride*7 stays in bounds
    size_t mid_region = buffer_size / 2;
    src1 = buffer + mid_region;
    src2 = buffer + mid_region + 20; // Ensure separation
    
    // Initialize accumulators
    H = 0;
    V = 0;
}