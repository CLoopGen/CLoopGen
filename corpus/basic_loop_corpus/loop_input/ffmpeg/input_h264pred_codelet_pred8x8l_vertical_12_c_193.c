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

int y;
uint16_t *src;
int stride;
uint64_t a = 0xdeadbeefdeadbeefULL;
uint64_t b = 0xc0defeedc0defeedULL;

void init_vars() {
    const size_t data_size = 16 * 1024 * 1024; // 16 MB to ensure sufficient runtime (~0.01 sec)
    src = (uint16_t *)aligned_alloc(64, data_size);
    if (!src) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    stride = 512; // stride in units of uint16_t

    // Ensure that y from 1 to 7 accesses valid memory
    // Maximum index: y=7 -> offset = 7 * stride + 2 * (sizeof(uint64_t)/sizeof(uint16_t)) = 7*stride + 8
    size_t required_elements = 7 * stride + 8;
    if (required_elements * sizeof(uint16_t) > data_size) {
        fprintf(stderr, "Buffer too small for loop bounds\n");
        exit(1);
    }

    // Initialize buffer to zero
    for (size_t i = 0; i < data_size / sizeof(uint16_t); i++) {
        src[i] = 0;
    }
}