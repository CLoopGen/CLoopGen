#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

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
    const size_t total_size = 1 << 20; // 1MB of data
    src = aligned_alloc(64, total_size);
    if (!src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(src, 0, total_size);

    stride = 64 / sizeof(uint16_t); // Ensure 64-byte alignment between rows
    a = 0x123456789ABCDEF0ULL;
    i = 0;
}

__attribute__((destructor))
void cleanup() {
    free(src);
}