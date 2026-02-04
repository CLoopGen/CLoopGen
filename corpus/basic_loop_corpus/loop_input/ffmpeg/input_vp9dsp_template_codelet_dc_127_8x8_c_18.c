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

ptrdiff_t stride = 16;
uint8_t *dst;
uint32_t val = 0xdeadbeef;
int y;

void init_vars() {
    const size_t total_size = 16 * 8; // 8 rows, each with 16 bytes stride
    uint8_t *buffer = aligned_alloc(32, total_size);
    if (!buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    dst = buffer;
    val = 0xdeadbeef;
    stride = 16;
}