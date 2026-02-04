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

uint16_t *src_base;
size_t total_size = 64 * 1024 * 1024; // ~128MB of uint16_t data (each uint16_t is 2 bytes)

void init_vars() {
    stride = 16; // ensures each src += stride advances by 16 elements (32 bytes)
    dcsplat = 0x0F0F0F0F0F0F0F0FULL;
    src_base = aligned_alloc(64, total_size);
    if (!src_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    src = src_base;
}

__attribute__((destructor)) void cleanup() {
    free(src_base);
}