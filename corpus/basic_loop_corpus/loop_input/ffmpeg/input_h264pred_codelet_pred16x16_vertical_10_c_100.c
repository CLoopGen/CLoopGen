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
    internal_stride = 8; 
    stride = internal_stride;

    size_t total_elements = 16 * stride * 4; 
    internal_src_buffer = aligned_alloc(64, total_elements * sizeof(uint16_t));
    if (!internal_src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_elements; ++idx) {
        internal_src_buffer[idx] = (uint16_t)(idx & 0xFFFF);
    }

    src = internal_src_buffer;
}

__attribute__((destructor)) void cleanup() {
    if (internal_src_buffer) {
        free(internal_src_buffer);
    }
}