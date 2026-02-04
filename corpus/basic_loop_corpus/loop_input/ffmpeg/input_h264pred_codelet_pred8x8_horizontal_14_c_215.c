#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint64_t u64;
    uint32_t u32[2];
    uint16_t u16[4];
    uint8_t u8[8];
    double f64;
    float f32[2];
} av_alias64;

ptrdiff_t stride;
int i;
uint16_t *src;

void init_vars() {
    const size_t data_size = 16 * 1024 * 1024; // 16MB to ensure ~0.01s runtime
    src = (uint16_t*)aligned_alloc(64, data_size);
    if (!src) {
        exit(1);
    }
    
    // Initialize all elements to avoid undefined behavior
    for (size_t idx = 0; idx < data_size / sizeof(uint16_t); idx++) {
        src[idx] = (uint16_t)(idx & 0xFFFF);
    }

    // Set stride such that accesses stay in bounds: i*stride >= 1 so that -1 + i*stride >= 0
    // We require for i=0: -1 + 0*stride is invalid, but loop uses i from 0 to 7
    // So we need at least: -1 + 7*stride < allocated_elements and -1 + 0*stride >= 0 -> not possible for i=0
    // But note: when i=0, index is -1 -> out of bounds unless we adjust base pointer

    // Adjust base so that src[-1] is valid: allocate extra space at beginning
    uint16_t* raw_ptr = (uint16_t*)aligned_alloc(64, data_size + 8 * sizeof(uint16_t));
    if (!raw_ptr) {
        exit(1);
    }
    for (size_t idx = 0; idx < (data_size + 8) / sizeof(uint16_t); idx++) {
        raw_ptr[idx] = (uint16_t)(idx & 0xFFFF);
    }
    src = raw_ptr + 1; // Now src[-1] points to raw_ptr[0]

    // Choose stride in elements (not bytes), must be at least 1
    stride = 1024; // Large enough to spread accesses, small enough to stay in bounds
}

// Explicitly define the loop function as external
extern void loop();