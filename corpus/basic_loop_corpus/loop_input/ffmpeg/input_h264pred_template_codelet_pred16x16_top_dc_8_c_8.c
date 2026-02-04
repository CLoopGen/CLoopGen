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
int i;
uint8_t *src;
uint32_t dcsplat;

uint8_t *src_buffer;

void init_vars() {
    dcsplat = 0xdeadbeef;
    stride = 16;
    
    size_t buffer_size = 16 * 16 * 1024; // Ensure enough space for ~0.01s of processing
    src_buffer = (uint8_t*)aligned_alloc(32, buffer_size);
    if (!src_buffer) {
        exit(1);
    }
    
    src = src_buffer;
}
