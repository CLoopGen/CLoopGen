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
uint8_t *src;
uint32_t dcsplat;

#define DATA_SIZE (64 * 1024 * 1024)  // 64 MB to target ~0.01 sec runtime
static uint8_t global_src_data[DATA_SIZE];

void init_vars() {
    stride = 16;  // ensures each iteration writes 16 bytes and steps by stride
    src = global_src_data;
    dcsplat = 0xDEADBEEF;  // arbitrary value for initialization
    i = 0;  // loop counter, reset in loop anyway
}