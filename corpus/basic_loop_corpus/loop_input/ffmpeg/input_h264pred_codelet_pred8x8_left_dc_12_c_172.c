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
uint16_t *src;

void init_vars() {
    // Set a reasonable data size to achieve ~0.01 seconds runtime
    // Aim for several million iterations; use 1MB of source data as baseline
    const size_t data_size_bytes = 1 << 20; // 1 MB
    const size_t num_elements = data_size_bytes / sizeof(uint16_t);
    
    // Allocate zeroed memory to avoid undefined behavior
    src = calloc(num_elements, sizeof(uint16_t));
    if (!src) {
        exit(1);
    }

    // Ensure that i=4 to i=7 accesses are valid: need at least 8 rows with stride spacing
    // Each iteration accesses (i * stride) offset, so we require: 7 * stride + 2*sizeof(uint64_t) <= data_size_bytes
    // => 7 * stride + 16 <= data_size_bytes
    // Choose stride in units of uint16_t to ensure alignment and coverage
    stride = (data_size_bytes / sizeof(uint16_t)) / 8; // ensures 8 rows fit

    // Initialize dc2splat with non-zero pattern for visibility
    dc2splat = 0x0123456789ABCDEFULL;

    // Validate that the loop bounds are safe
    // Loop runs i=4 to i=7 inclusive
    // Each iteration writes two uint64_t values starting at src + i*stride
    // That means we write 16 bytes per row, so we require:
    //   (i * stride) * sizeof(uint16_t) + 16 <= data_size_bytes
    // With our choice of stride, this should hold.
}