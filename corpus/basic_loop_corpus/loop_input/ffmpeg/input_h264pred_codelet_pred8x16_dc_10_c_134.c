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
uint64_t dc4splat;
uint64_t dc5splat;
uint16_t *src;

void init_vars() {
    dc4splat = 0x0101010101010101ULL;
    dc5splat = 0x0202020202020202ULL;
    stride = 16;
    int total_elements = 256 * (1 << 20) / sizeof(uint16_t);
    src = aligned_alloc(64, total_elements * sizeof(uint16_t));
    if (!src) {
        exit(1);
    }
}

__attribute__((destructor))
void cleanup() {
    free(src);
}