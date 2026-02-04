#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

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
size_t total_data_size = 16 * 1024 * 1024; // ~16MB to target ~0.01s runtime

void init_vars() {
    stride = 16;
    dcsplat = 0xdeadbeef;
    
    src_buffer = (uint8_t*)aligned_alloc(32, total_data_size);
    if (!src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    memset(src_buffer, 0, total_data_size);
    src = src_buffer;
}

__attribute__((destructor))
static void cleanup() {
    if (src_buffer) {
        free(src_buffer);
    }
}