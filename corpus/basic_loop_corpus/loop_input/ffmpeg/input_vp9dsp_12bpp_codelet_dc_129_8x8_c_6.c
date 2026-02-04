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

ptrdiff_t stride = 8;
uint16_t *dst;
uint64_t val = 0x123456789ABCDEF0ULL;
int y;

void init_vars() {
    const size_t total_size = 256 * 1024 * 1024; // 256 MB
    const size_t num_elements = total_size / sizeof(uint16_t);
    dst = aligned_alloc(16, total_size);
    if (!dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    val = 0x123456789ABCDEF0ULL;
    stride = 8;
}