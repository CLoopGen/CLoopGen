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

static uint16_t *src_buffer;
static size_t total_size = 1 << 20; // 1MB of data

void init_vars() {
    src_buffer = (uint16_t *)calloc(total_size, sizeof(uint16_t));
    if (!src_buffer) {
        exit(1);
    }
    src = src_buffer;
    stride = 8; 
    dc = 0x123456789ABCDEF0ULL;
    y = 0;
}