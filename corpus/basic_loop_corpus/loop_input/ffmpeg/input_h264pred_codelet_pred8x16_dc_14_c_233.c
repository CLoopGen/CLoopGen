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
uint64_t dc2splat;
uint64_t dc3splat;
uint16_t *src;

void init_vars() {
    // Set reasonable values for scalars
    stride = 16;  // Ensures sufficient spacing between rows
    dc2splat = 0x0101010101010101ULL;
    dc3splat = 0x0202020202020202ULL;

    // Allocate approximately 1MB of data (adjustable for timing)
    size_t total_size = 1 << 20;  // 1MB
    size_t num_elements = total_size / sizeof(uint16_t);
    src = (uint16_t *)aligned_alloc(64, total_size);
    if (!src) {
        exit(1);
    }

    // Initialize allocated memory to zero
    for (size_t idx = 0; idx < num_elements; idx++) {
        src[idx] = 0;
    }

    // Ensure that the loop indices (i=4 to 7) with stride access valid memory
    // Each iteration accesses two uint64_t blocks -> 16 bytes each -> 8 uint16_t elements per block
    // So each row accessed needs at least 16 uint16_t elements (128 bits * 2)
    // With i from 4 to 7: we access rows 4*stride, 5*stride, 6*stride, 7*stride
    // Make sure max index is within bounds: 7 * stride + (offset within row) < num_elements
    // Max offset within row: ((uint64_t*)(row)) + 1 -> second uint64_t in the row => 2nd 8-byte chunk => 8 uint16_t
    // So max element index accessed: 7 * stride + 8
    if (7 * stride + 8 > num_elements) {
        exit(1);
    }
}