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

#define DATA_SIZE (64 * 1024 * 1024)  // 64MB to target ~0.01 sec runtime
static uint8_t global_data[DATA_SIZE];

void init_vars() {
    dst = global_data;
    val = 0xdeadbeef;
    stride = 16;  // Ensure we don't go out of bounds: 8 rows * 8 bytes each = 64 bytes written
}