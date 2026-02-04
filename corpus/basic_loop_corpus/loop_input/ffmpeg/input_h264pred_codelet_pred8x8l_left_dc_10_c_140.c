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

uint16_t *src;
int stride;
uint64_t dc;
int y;

static uint16_t *buffer;
static size_t buffer_size;

void init_vars() {
    buffer_size = 1 << 20; // 1MB of data (adjustable for ~0.01 sec runtime)
    buffer = aligned_alloc(64, buffer_size);
    if (!buffer) {
        exit(1);
    }

    src = buffer;
    stride = 8; // ensures we move by 8 * sizeof(uint16_t) = 16 bytes per row
    dc = 0x123456789ABCDEF0ULL;

    // Ensure that accessing up to (src + 1 * sizeof(uint64_t*)) in each iteration is safe
    // Each iteration accesses two uint64_t locations: offset 0 and 1 (i.e., 16 bytes total)
    // We have 8 iterations, with src incremented by 'stride' (in uint16_t units) each time
    // So total memory needed: 8 * stride + (16 / sizeof(uint16_t)) = 8*8 + 8 = 72 uint16_t elements minimum
    // Our buffer has plenty: 1MB / 2 = 524288 elements
}

__attribute__((destructor))
static void cleanup() {
    free(buffer);
}