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
    stride = 32; // matches the step in dst += stride and 8 writes of 8 bytes (32 uint16_t)
    
    // Allocate large buffer to ensure meaningful runtime (~0.01 sec on modern CPU)
    buffer = aligned_alloc(64, DATA_SIZE);
    if (!buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    dst = buffer;
}

__attribute__((destructor))
static void cleanup() {
    free(buffer);
}