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
uint32_t p4a = 0xdeadbeef;
uint32_t p4b = 0xcafebabe;
uint32_t p4c = 0xba5eba11;
uint32_t p4d = 0x1337f00d;
uint32_t p4e = 0xbaddad1d;
uint32_t p4f = 0xfacefeed;
uint32_t p4g = 0xfadeac1d;
uint32_t p4h = 0xacc1dbad;
int y;

uint8_t *base_dst;

void init_vars() {
    const size_t total_size = 16 * 1024 * 1024; // 16 MB to ensure measurable runtime
    base_dst = (uint8_t *)aligned_alloc(32, total_size);
    if (!base_dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    dst = base_dst;
}