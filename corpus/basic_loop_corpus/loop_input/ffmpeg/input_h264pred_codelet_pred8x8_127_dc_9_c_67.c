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
uint64_t a;
uint16_t *src;

uint16_t *src_buffer;

void init_vars() {
    const size_t total_size = 1 << 20; // 1MB of data
    src_buffer = aligned_alloc(64, total_size);
    if (!src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize buffer with some values
    for (size_t idx = 0; idx < total_size / sizeof(uint16_t); idx++) {
        src_buffer[idx] = (uint16_t)(idx & 0xFFFF);
    }

    // Set external variables
    stride = 16; // ensures we don't go out of bounds over 8 iterations
    i = 0;
    a = 0xdeadbeefdeadbeefULL;
    src = src_buffer;
}