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

uint8_t *src;
int stride;
uint32_t dc;
int y;

static uint8_t *buffer;
static size_t buffer_size = 1 << 20; // 1MB

void init_vars() {
    buffer = (uint8_t *)aligned_alloc(32, buffer_size);
    if (!buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = buffer;
    stride = 8;
    dc = 0xdeadbeef;
    y = 0;
}

__attribute__((destructor))
static void cleanup() {
    free(buffer);
}