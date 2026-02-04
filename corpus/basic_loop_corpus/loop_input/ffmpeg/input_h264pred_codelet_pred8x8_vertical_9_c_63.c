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

int i;
uint16_t *src;
int stride;
uint64_t a = 0x1122334455667788ULL;
uint64_t b = 0x99AABBCCDDEEFF00ULL;

void init_vars() {
    const size_t total_size = 256 * 1024 * 1024; // 256 MB
    src = aligned_alloc(64, total_size);
    if (!src) {
        exit(1);
    }
    stride = 8; // ensures alignment and reasonable access pattern

    for (int j = 0; j < total_size / sizeof(uint16_t); j++) {
        src[j] = j & 0xFFFF;
    }
}