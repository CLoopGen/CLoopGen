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
uint16_t *dst;
uint64_t val;
int y;

static uint16_t *buffer;

void init_vars() {
    const size_t total_size = 1 << 20; // 1MB of data
    buffer = aligned_alloc(64, total_size);
    if (!buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    dst = buffer;
    stride = 16; // ensures 4x u64 stores (32 bytes) fit within each row
    val = 0x123456789ABCDEF0ULL;
}

__attribute__((destructor))
static void cleanup() {
    free(buffer);
}