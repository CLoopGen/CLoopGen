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

int i;
uint8_t *src;
int stride;
uint32_t a = 0x12345678;
uint32_t b = 0xabcdef01;
uint32_t c = 0x23456789;
uint32_t d = 0xbcdef012;

static uint8_t *internal_src_buffer;

void init_vars() {
    stride = 16; 
    size_t total_size = 16 * stride * sizeof(uint32_t) * 4 + 128; 
    internal_src_buffer = (uint8_t*)aligned_alloc(32, total_size);
    if (!internal_src_buffer) {
        exit(1);
    }
    src = internal_src_buffer;
}

__attribute__((destructor)) void cleanup_vars() {
    if (internal_src_buffer) {
        free(internal_src_buffer);
    }
}