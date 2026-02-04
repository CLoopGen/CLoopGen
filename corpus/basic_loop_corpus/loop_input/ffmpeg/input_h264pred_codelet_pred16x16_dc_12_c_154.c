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

static uint16_t *buffer;

void init_vars() {
    const size_t total_size = 1 << 20; // 1MB of data
    buffer = aligned_alloc(64, total_size);
    if (!buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    stride = 16; // Each iteration advances by 16 uint16_t elements (32 bytes)
    src = buffer;
    dcsplat = 0x07FF07FF07FF07FFULL; // Example constant value
}

__attribute__((destructor))
static void cleanup() {
    free(buffer);
}