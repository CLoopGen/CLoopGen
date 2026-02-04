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

ptrdiff_t stride;
int i;
uint32_t dc0splat;
uint32_t dc1splat;
uint8_t *src;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of input data
    stride = 16; // Ensure alignment and spacing
    dc0splat = 0xdeadbeef;
    dc1splat = 0xcafebabe;

    src = aligned_alloc(32, data_size);
    if (!src) {
        exit(1);
    }
}

__attribute__((destructor))
static void cleanup() {
    free(src);
}