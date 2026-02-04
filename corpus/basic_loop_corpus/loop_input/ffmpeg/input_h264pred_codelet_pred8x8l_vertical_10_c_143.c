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

int y;
uint16_t *src;
int stride;
uint64_t a = 0xAAAAAAAA55555555ULL;
uint64_t b = 0x123456789ABCDEF0ULL;

void init_vars() {
    const size_t total_size = 16 * 1024 * 1024; // 16 MB to ensure ~0.01 sec runtime
    src = aligned_alloc(64, total_size);
    if (!src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    stride = 64 / sizeof(uint16_t); // 64-byte alignment per row

    for (int i = 0; i < 8; i++) {
        uint64_t* base = (uint64_t*)(src + i * stride);
        for (int j = 0; j < 8; j++) {
            ((av_alias64*)&base[j])->u64 = 0;
        }
    }
}