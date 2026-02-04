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
    const size_t data_size = 256 * 1024 * 1024; // 256 MB of input data
    src = (uint16_t *)aligned_alloc(64, data_size);
    if (!src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    stride = (data_size / sizeof(uint16_t)) / 16; // Ensure valid access over 8 iterations with offset

    for (size_t idx = 0; idx < data_size / sizeof(uint16_t); ++idx) {
        src[idx] = (uint16_t)(idx % 65535);
    }
}

extern void loop();

__attribute__((constructor))
static void setup() {
    init_vars();
}