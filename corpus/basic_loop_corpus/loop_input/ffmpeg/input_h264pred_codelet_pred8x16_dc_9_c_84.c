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

ptrdiff_t stride = 16;
int i = 0;
uint64_t dc4splat = 0x0F0F0F0F0F0F0F0FULL;
uint64_t dc5splat = 0xF0F0F0F0F0F0F0F0ULL;
uint16_t *src = NULL;

static uint16_t *internal_src = NULL;

void init_vars() {
    const size_t data_size = 1 << 20;
    internal_src = aligned_alloc(64, data_size * sizeof(uint16_t));
    if (!internal_src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    src = internal_src;
}