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
uint64_t dc0splat;
uint64_t dc1splat;
uint16_t *src;

void init_vars() {
    // Set stride to a reasonable value: 64 elements (128 bytes) to allow spatial separation
    stride = 64;

    // Initialize DC splat values
    dc0splat = 0x0123456789ABCDEFULL;
    dc1splat = 0xFEDCBA9876543210ULL;

    // Allocate enough data to make the loop meaningful and take measurable time
    // The loop runs from i=4 to i<8, so we need at least i=7 * stride + some offset for two uint64_t writes
    // Each write accesses two uint64_t -> 16 bytes -> 8 uint16_t elements
    // So we need at least (7 * stride + 8) uint16_t elements
    size_t required_elements = 7 * stride + 8;
    // Aim for ~64MB of data to ensure measurable runtime (~0.01 sec on modern CPU)
    // But base it on stride; if stride is large, we may already cover enough ground
    size_t target_size = 64 * (1 << 20); // 64 MB
    size_t alloc_elements = required_elements > (target_size / sizeof(uint16_t)) ?
                           required_elements : (target_size / sizeof(uint16_t));

    src = (uint16_t *)aligned_alloc(64, alloc_elements * sizeof(uint16_t));
    if (!src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize allocated memory to zero
    for (size_t idx = 0; idx < alloc_elements; idx++) {
        src[idx] = 0;
    }
}

// Ensure symbols are defined and can be linked