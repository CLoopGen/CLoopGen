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
uint16_t *dst;
uint64_t val;
int y;

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB of data
static uint16_t *buffer;

void init_vars() {
    // Allocate large buffer to ensure meaningful runtime (~0.01 sec on modern CPU)
    buffer = (uint16_t *)aligned_alloc(64, DATA_SIZE);
    if (!buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize variables
    dst = buffer;
    stride = 32; // Advance by 32 uint16_t elements (64 bytes) per iteration
    val = 0x123456789ABCDEF0ULL;

    // Ensure that memory accesses in the loop do not go out of bounds
    // Each iteration writes 8× uint64_t via av_alias64 at offsets 0 to 28 (each +4 in uint16_t units)
    // So each row needs at least 32 uint16_t (64 bytes)
    // With 32 iterations and stride=32, total required: 32 * 32 = 1024 uint16_t minimum
    // Our buffer is much larger (128MB), so it's safe
}