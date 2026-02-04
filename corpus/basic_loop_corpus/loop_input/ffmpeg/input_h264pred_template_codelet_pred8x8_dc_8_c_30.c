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
int i;
uint32_t dc2splat = 0xCAFEBABE;
uint32_t dc3splat = 0xDEADBEEF;
uint8_t *src;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of input data
    src = aligned_alloc(16, data_size);
    if (!src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}