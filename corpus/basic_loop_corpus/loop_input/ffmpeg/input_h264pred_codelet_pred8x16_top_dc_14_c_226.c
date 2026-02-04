#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
int dc0;
int dc1;
uint16_t *src;

static uint16_t *src_buffer;

void init_vars() {
    // Ensure safe memory access: loop accesses indices [i - stride] and [4 + i - stride] for i in [0,3]
    // So we need valid memory from min_index = 0 - stride to max_index = 7 - stride
    // Choose stride such that all accessed indices are within allocated buffer
    // Set stride = 4 to make base index -4, so we need at least 8 elements before logical "start"
    stride = 4;
    
    // Total buffer size: we want large enough data to take ~0.01s
    // Each iteration does 8 memory accesses (2 per loop, 4 iterations)
    // Assume modern CPU can do ~1e9 mem ops/sec -> 1e7 ops in 0.01s -> need ~1e7/8 = 1.25e6 iterations?
    // But our loop is fixed (only 4 iterations). The timing must come from repeated calls elsewhere.
    // Therefore, allocate reasonably large array to support many potential loop calls
    const size_t total_size = 64 * 1024 * 1024; // 64MB of uint16_t -> 128MB bytes
    src_buffer = (uint16_t*)aligned_alloc(64, total_size * sizeof(uint16_t));
    
    if (!src_buffer) {
        // fallback to smaller allocation if needed
        src_buffer = (uint16_t*)malloc(8192 * sizeof(uint16_t));
        for (size_t i = 0; i < 8192; i++) {
            src_buffer[i] = (uint16_t)(i & 0xFFFF);
        }
    } else {
        // Initialize large buffer
        for (size_t i = 0; i < total_size; i++) {
            src_buffer[i] = (uint16_t)(i & 0xFFFF);
        }
    }
    
    // Set src pointer so that [ -stride ] lands inside valid memory
    // We allocated plenty of space at beginning, so set src = src_buffer + stride
    // Then src[i - stride] = src_buffer[i], which is valid for i=0..7
    src = src_buffer + stride;
    
    // Initialize accumulators
    dc0 = 0;
    dc1 = 0;
}