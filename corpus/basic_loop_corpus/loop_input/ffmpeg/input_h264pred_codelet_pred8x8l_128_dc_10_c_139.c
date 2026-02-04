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
int y;

static uint16_t *src_buffer;
static size_t total_data_size = 1 << 20; // 1MB of data

void init_vars() {
    src_buffer = aligned_alloc(64, total_data_size);
    if (!src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    stride = 8; // ensures we step by 8 uint16_t elements per iteration (safe for 8 iterations)
    src = src_buffer;
}

__attribute__((destructor))
static void cleanup() {
    free(src_buffer);
}