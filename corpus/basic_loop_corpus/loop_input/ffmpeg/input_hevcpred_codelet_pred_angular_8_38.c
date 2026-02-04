#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

ptrdiff_t stride;
int size;
int x;
int y;
uint8_t *src;
int angle;
uint8_t *ref;

void init_vars() {
    size = 1024;
    stride = size;
    angle = 32;
    src = (uint8_t*)aligned_alloc(32, (size_t)stride * size * sizeof(uint8_t));
    ref = (uint8_t*)aligned_alloc(32, (size_t)(size + size + 10) * sizeof(uint8_t));

    for (int i = 0; i < (size + size + 10); i++) {
        ref[i] = rand() & 0xFF;
    }
    for (int i = 0; i < stride * size; i++) {
        src[i] = 0;
    }
}