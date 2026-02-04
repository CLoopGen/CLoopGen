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
uint64_t p4a;
uint64_t p4b;
uint64_t p4c;
uint64_t p4d;
int y;

static uint16_t *dst_buffer;
static ptrdiff_t effective_stride;

void init_vars() {
    p4a = 0x0F0F0F0F0F0F0F0FULL;
    p4b = 0xAAAAAAAAAAAAAAAAULL;
    p4c = 0x5555555555555555ULL;
    p4d = 0xF0F0F0F0F0F0F0F0ULL;

    effective_stride = 16; 
    stride = effective_stride;

    size_t total_size = 256 * 1024 * 1024; 
    dst_buffer = aligned_alloc(64, total_size);
    if (!dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    dst = dst_buffer;
}