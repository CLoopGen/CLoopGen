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
uint64_t c = 0xFFEEDDCCBBAA9988ULL;
uint64_t d = 0x7766554433221100ULL;

static uint16_t *internal_src_buffer;
static int internal_stride;

void init_vars() {
    internal_stride = 8; // stride in units of uint16_t
    stride = internal_stride;

    // Allocate approximately 64MB of data to ensure loop runtime ~0.01s
    // Each iteration writes 4 * 8 bytes = 32 bytes per row
    // 16 rows -> 16 * 32 = 512 bytes per stride block
    // Total size: need enough rows so that i*stride doesn't overflow and we can access up to (i + 1)*stride with offset
    // We write to indices: [i * stride + 0], ..., [i * stride + 3] in units of uint64_t -> each is 4 * 8 / 2 = 16 uint16_t elements
    // So we need at least (i * stride + 16) per row, max i=15 -> index = 15*stride + 16 = 15*8 + 16 = 136 uint16_t elements
    // But to make it heavier for timing, allocate large buffer

    size_t total_elements = 8 * 1024 * 1024; // ~16 MB in uint16_t (~32MB memory)
    internal_src_buffer = aligned_alloc(64, total_elements * sizeof(uint16_t));
    if (!internal_src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = internal_src_buffer;

    // Initialize some pattern to avoid all-zero
    for (size_t j = 0; j < total_elements; j++) {
        internal_src_buffer[j] = (uint16_t)(j & 0xFFFF);
    }
}