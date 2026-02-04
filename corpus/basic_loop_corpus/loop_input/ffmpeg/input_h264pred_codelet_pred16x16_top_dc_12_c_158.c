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
uint64_t dcsplat;

static uint16_t *src_buffer;

void init_vars() {
    const size_t total_size = 16 * 1024 * 1024; // 16 MB of data
    src_buffer = aligned_alloc(64, total_size);
    if (!src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    stride = 16; // Advance by 16 uint16_t elements (32 bytes) per iteration
    src = src_buffer;
    dcsplat = 0x123456789ABCDEF0ULL;
}

__attribute__((destructor))
static void cleanup() {
    free(src_buffer);
}