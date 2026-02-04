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
uint8_t *dst;
uint32_t val;
int y;

uint8_t *base_dst;
size_t total_size = 1 << 20; // 1MB

void init_vars() {
    stride = 32;
    val = 0xdeadbeef;
    base_dst = calloc(total_size, 1);
    if (!base_dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    dst = base_dst;
}

__attribute__((destructor))
static void cleanup() {
    free(base_dst);
}