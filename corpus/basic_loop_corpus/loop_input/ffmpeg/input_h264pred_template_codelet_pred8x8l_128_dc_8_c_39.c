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
int y;

static uint8_t *buffer;
static size_t total_size = 64 * 1024 * 1024; // 64 MB for sufficient runtime (~0.01 sec)

void init_vars() {
    buffer = (uint8_t *)aligned_alloc(32, total_size);
    if (!buffer) {
        exit(1);
    }
    src = buffer;
    stride = 8;
}

__attribute__((destructor))
static void cleanup() {
    free(buffer);
}