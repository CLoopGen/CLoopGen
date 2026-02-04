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

static uint16_t *src_data;
static uint16_t *ref_data;

void init_vars() {
    size = 2048;
    stride = size;
    angle = 32;
    src_data = (uint16_t*)aligned_alloc(64, sizeof(uint16_t) * size * stride);
    ref_data = (uint16_t*)aligned_alloc(64, sizeof(uint16_t) * (size + 4));
    if (!src_data || !ref_data) {
        exit(1);
    }
    src = src_data;
    ref = ref_data;
    for (int i = 0; i < size * stride; i++) {
        src_data[i] = 0;
    }
    for (int i = 0; i < size + 4; i++) {
        ref_data[i] = (uint16_t)(i * 31);
    }
}