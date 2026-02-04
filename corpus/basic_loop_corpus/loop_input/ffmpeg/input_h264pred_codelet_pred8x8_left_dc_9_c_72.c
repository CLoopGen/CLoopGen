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
uint64_t dc2splat;
uint16_t *src;

void init_vars() {
    const size_t total_size = 1 << 20; // 1MB of data
    src = (uint16_t*)aligned_alloc(64, total_size);
    if (!src) exit(1);

    stride = 256 / sizeof(uint16_t); // ensures alignment and spacing

    dc2splat = 0xdeadbeefdeadbeefULL;

    for (size_t idx = 0; idx < total_size / sizeof(uint16_t); idx++) {
        src[idx] = (uint16_t)(idx & 0xFFFF);
    }
}