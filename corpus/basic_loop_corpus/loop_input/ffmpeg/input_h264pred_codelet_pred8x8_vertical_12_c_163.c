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
uint64_t a;
uint64_t b;

void init_vars() {
    a = 0x123456789ABCDEF0ULL;
    b = 0xFEDCBA9876543210ULL;
    stride = 8;
    size_t total_elements = 256 * 1024 * 1024 / sizeof(uint16_t); // ~256MB of data
    src = (uint16_t*)aligned_alloc(64, total_elements * sizeof(uint16_t));
    if (!src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}

__attribute__((destructor))
void cleanup() {
    if (src) {
        free(src);
    }
}