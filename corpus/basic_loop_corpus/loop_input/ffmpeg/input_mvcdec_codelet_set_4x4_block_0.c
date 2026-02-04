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

uint8_t *dst;
int linesize;
uint32_t pixel;
int i;
int j;

static uint8_t *internal_dst;
static int internal_linesize = 1024; // 4x4 block stride of 1024 bytes (aligned)
static const size_t data_size = 268435456; // 256 MB

void init_vars() {
    internal_dst = aligned_alloc(32, data_size);
    if (!internal_dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    dst = internal_dst;
    linesize = internal_linesize;
    pixel = 0xdeadbeef;
    i = 0;
    j = 0;
}