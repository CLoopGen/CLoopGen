#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

ptrdiff_t stride;
int i;
uint32_t dc6splat;
uint32_t dc7splat;
uint8_t *src;

void init_vars() {
    stride = 64;
    dc6splat = 0xdeadbeef;
    dc7splat = 0xc0ffee00;
    
    size_t total_size = 16 * stride;
    src = aligned_alloc(32, total_size);
    if (!src) {
        exit(1);
    }
    memset(src, 0, total_size);
}

__attribute__((destructor))
void cleanup() {
    if (src) {
        free(src);
    }
}