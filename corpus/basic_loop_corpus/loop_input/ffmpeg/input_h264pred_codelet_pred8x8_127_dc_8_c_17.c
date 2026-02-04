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
uint32_t a;
uint8_t *src;

void init_vars() {
    stride = 8;
    a = 0xdeadbeef;
    size_t total_size = 256 * 1024 * 1024;
    src = aligned_alloc(32, total_size);
    if (!src) {
        exit(1);
    }
}