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
int i;
uint8_t *src;

#define DATA_SIZE (16 * 1024 * 1024) // 16 MB to target ~0.01 sec runtime
static uint8_t global_src[DATA_SIZE];

void init_vars() {
    src = global_src;
}