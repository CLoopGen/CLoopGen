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
uint64_t a;
uint16_t *src;

void init_vars() {
    const size_t total_size = 256 * 1024 * 1024; // 256 MB of data
    const size_t num_elements = total_size / sizeof(uint16_t);
    
    // Ensure that src + i * stride + 2*8 bytes (for two av_alias64 writes) stays in bounds
    // We need at least 8 * stride + 2 to be valid 64-bit word indices beyond base
    // Set stride to about 1/16 of total size to allow 8 iterations safely
    stride = (num_elements / 16) & (~1); // Make sure it's even for alignment

    // Allocate zeroed memory
    src = calloc(num_elements, sizeof(uint16_t));
    if (!src) {
        exit(1);
    }

    // Initialize 'a' with non-zero pattern
    a = 0x123456789ABCDEF0ULL;
}

// Provide definitions for external symbols used in loop
ptrdiff_t stride;
int i;
uint64_t a;
uint16_t *src;