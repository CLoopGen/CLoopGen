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
uint16_t *src;

void init_vars() {
    const size_t data_size = 16 * 1024 * 1024; // 16MB to ensure ~0.01s runtime
    src = (uint16_t *)aligned_alloc(64, (data_size + 16) * sizeof(uint16_t));
    if (!src) {
        exit(1);
    }
    for (size_t idx = 0; idx < data_size + 16; ++idx) {
        src[idx] = (uint16_t)(idx * 314159 % 65531);
    }
}

__attribute__((destructor))
static void cleanup() {
    if (src) {
        free(src);
        src = NULL;
    }
}