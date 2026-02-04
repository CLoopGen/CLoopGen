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
uint64_t a;
uint16_t *src;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data
    src = aligned_alloc(64, data_size * sizeof(uint16_t));
    if (!src) {
        exit(1);
    }

    stride = (data_size / 8) / sizeof(uint16_t); // Ensure access fits within bounds
    a = 0xdeadbeefdeadbeefULL;

    for (int j = 0; j < data_size; j++) {
        src[j] = (uint16_t)(j & 0xFFFF);
    }
}