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

ptrdiff_t stride;
uint8_t *dst;
uint32_t dc;
int y;

#define DATA_SIZE (128 << 20) // 128 MB
static uint8_t *buffer;

void init_vars() {
    buffer = (uint8_t *)aligned_alloc(32, DATA_SIZE);
    if (!buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    stride = 32;
    dst = buffer;
    dc = 0xdeadbeef;
    y = 0;
}

__attribute__((destructor))
static void cleanup() {
    free(buffer);
}