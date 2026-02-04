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
uint64_t a = 0x0F0E0D0C0B0A0908ULL;
uint64_t b = 0x0706050403020100ULL;
uint64_t c = 0x8899AABBCCDDEEFFULL;
uint64_t d = 0x1122334455667788ULL;

void init_vars() {
    const size_t total_size_bytes = 16 * 1024 * 1024; // 16MB to ensure ~0.01s runtime
    const size_t num_uint16 = total_size_bytes / sizeof(uint16_t);
    src = aligned_alloc(64, total_size_bytes);
    if (!src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < num_uint16; ++idx) {
        src[idx] = (uint16_t)(idx & 0xFFFF);
    }

    stride = 8; // ensures we step by 8 uint16_t elements per iteration
}

__attribute__((destructor))
static void cleanup() {
    free(src);
}