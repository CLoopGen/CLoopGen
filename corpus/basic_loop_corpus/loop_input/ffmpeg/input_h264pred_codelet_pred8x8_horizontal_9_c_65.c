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
uint16_t *src;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data
    src = aligned_alloc(64, data_size);
    if (!src) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size / sizeof(uint16_t); ++idx) {
        src[idx] = (uint16_t)(idx * 7 + 1);
    }

    stride = (data_size / sizeof(uint16_t)) / 16;
}

__attribute__((unused))
static void ensure_no_aliasing_issues() {
    av_alias64 dummy;
    dummy.u64 = 0;
}