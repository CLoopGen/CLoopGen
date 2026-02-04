#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

ptrdiff_t stride;
int size;
int x;
int y;
uint16_t *src;
int angle;
uint16_t *ref;

void init_vars() {
    size = 2048;
    stride = size;
    angle = 32;
    src = (uint16_t*)aligned_alloc(64, sizeof(uint16_t) * size * stride);
    ref = (uint16_t*)aligned_alloc(64, sizeof(uint16_t) * (size * stride + size + 10));

    for (int i = 0; i < size * stride; i++) {
        src[i] = 0;
    }
    for (int i = 0; i < size * stride + size + 10; i++) {
        ref[i] = (i * 524287) % 65531;
    }
}