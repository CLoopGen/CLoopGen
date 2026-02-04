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

ptrdiff_t stride = 32;
uint8_t *dst;
uint32_t dc = 0xdeadbeef;
int y;

uint8_t *base_dst;

void init_vars() {
    size_t total_size = 32 * 32; // 32 rows, each with 32 bytes written
    base_dst = aligned_alloc(32, total_size);
    if (!base_dst) {
        exit(1);
    }
    dst = base_dst;
}

__attribute__((destructor))
static void cleanup() {
    free(base_dst);
}