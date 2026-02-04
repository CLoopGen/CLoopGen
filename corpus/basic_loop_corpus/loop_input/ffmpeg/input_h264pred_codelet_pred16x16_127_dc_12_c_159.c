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

static uint16_t data[1 << 21]; // ~2MB of data (1<<21) elements

void init_vars() {
    for (size_t j = 0; j < (sizeof(data) / sizeof(data[0])); j++) {
        data[j] = 0;
    }
    src = data;
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}