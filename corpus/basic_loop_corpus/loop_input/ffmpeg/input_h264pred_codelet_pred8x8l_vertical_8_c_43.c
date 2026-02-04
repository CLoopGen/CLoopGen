#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

int y;
uint8_t *src;
int stride;
uint32_t a = 0xdeadbeef;
uint32_t b = 0xcafebabe;

static uint8_t *internal_src;
static int internal_stride;

void init_vars() {
    internal_stride = 64;
    stride = internal_stride;

    size_t total_size = 256 * 1024 * 1024; // 256 MB
    internal_src = (uint8_t *)aligned_alloc(32, total_size);
    if (!internal_src) {
        exit(1);
    }
    src = internal_src;

    for (size_t i = 0; i < total_size; i++) {
        internal_src[i] = (uint8_t)(i & 0xFF);
    }

    a = 0xdeadbeef;
    b = 0xcafebabe;
}