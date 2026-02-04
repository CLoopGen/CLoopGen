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
    val = 0x123456789ABCDEF0ULL;
    stride = 32; // each iteration advances by 32 uint16_t elements (64 bytes)
    
    // Allocate buffer to ensure we don't go out of bounds
    // Loop runs 32 iterations, each accessing up to offset 28 (each +4 uint16_t step -> 7*4=28)
    // So we need at least 32 (stride steps) * 32 (max offset per step) = 1024 elements safety margin
    // But allocate much more to meet data size requirement
    buffer = aligned_alloc(64, DATA_SIZE);
    if (!buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    dst = buffer;
}