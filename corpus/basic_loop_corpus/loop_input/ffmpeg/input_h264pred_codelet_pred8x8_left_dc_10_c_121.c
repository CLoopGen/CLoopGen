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
uint16_t *src;

void init_vars() {
    // Ensure total data size is large enough for ~0.01 sec runtime
    // Each iteration accesses 2 uint64_t values (16 bytes) per row
    // 4 iterations => 4 rows, each separated by 'stride' in uint16_t units
    // So we need at least 4 * stride * sizeof(uint16_t) bytes

    // Aim for about 64MB of effective data to ensure non-trivial runtime
    // Let's set stride to 8192 uint16_t elements (16384 bytes per row)
    stride = 8192;

    // Initialize dc0splat with non-zero pattern
    dc0splat = 0x0F0F0F0F0F0F0F0FULL;

    // Allocate memory for 4 rows, each with at least 16 bytes (8 uint64_t worth, but we only use 2)
    // But allocate full stride for each row
    size_t total_size = 4 * stride * sizeof(uint16_t);
    src = aligned_alloc(64, total_size);
    if (!src) {
        exit(1);
    }

    // Initialize allocated memory to zero
    for (size_t idx = 0; idx < total_size / sizeof(uint16_t); idx++) {
        src[idx] = 0;
    }
}