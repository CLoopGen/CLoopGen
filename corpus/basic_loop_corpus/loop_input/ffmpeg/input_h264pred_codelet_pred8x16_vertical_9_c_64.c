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
uint64_t a = 0xAAAAAAAAAAAAAAAAULL;
uint64_t b = 0xBBBBBBBBBBBBBBBBULL;

static uint16_t *internal_src_buffer;
static int internal_stride;

void init_vars() {
    const size_t total_size = 1 << 20; // 1MB of data
    internal_stride = 8; // stride in units of uint16_t

    internal_src_buffer = aligned_alloc(64, total_size);
    if (!internal_src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_size / sizeof(uint16_t); idx++) {
        internal_src_buffer[idx] = (uint16_t)(idx & 0xFFFF);
    }

    src = internal_src_buffer;
    stride = internal_stride;
}