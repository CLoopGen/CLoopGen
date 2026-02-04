#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

ptrdiff_t stride = 16;
uint8_t *dst;
uint32_t p4a = 0xCAFEBABE;
uint32_t p4b = 0xDEADBEEF;
int y;

void init_vars() {
    const size_t total_size = 16 * 8; // 8 iterations, each accessing up to dst + 4 + 4 = 8 bytes, with stride 16
    dst = aligned_alloc(32, total_size);
    if (!dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}