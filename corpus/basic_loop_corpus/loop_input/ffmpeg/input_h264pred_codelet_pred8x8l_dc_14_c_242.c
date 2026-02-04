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

uint16_t *src;
int stride;
uint64_t dc;
int y;

static uint16_t *buffer;
static size_t buffer_size;

void init_vars() {
    buffer_size = 16 * 1024 * 1024; // 16 MB of data to ensure ~0.01 sec runtime
    buffer = aligned_alloc(64, buffer_size);
    if (!buffer) {
        exit(1);
    }

    src = buffer;
    stride = 16; // stride in units of uint16_t: ensures alignment and safe access
    dc = 0x0123456789ABCDEFULL;
    y = 0;
}