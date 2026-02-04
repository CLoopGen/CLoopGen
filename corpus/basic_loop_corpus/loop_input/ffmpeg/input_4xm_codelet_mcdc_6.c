#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

uint16_t *dst;
uint16_t *src;
int h;
int stride;
int scale;
unsigned int dc;
int i;

#define DATA_SIZE (64 << 20)  // 64 MB of data
#define WIDTH 1024
static uint16_t src_data[DATA_SIZE / sizeof(uint16_t)];
static uint16_t dst_data[DATA_SIZE / sizeof(uint16_t)];

void init_vars() {
    h = DATA_SIZE / WIDTH / sizeof(uint16_t);
    stride = WIDTH / sizeof(uint16_t);
    scale = 2;
    dc = 1024;

    src = src_data;
    dst = dst_data;

    for (size_t idx = 0; idx < DATA_SIZE / sizeof(uint16_t); ++idx) {
        src_data[idx] = (uint16_t)(idx % 65535);
        dst_data[idx] = 0;
    }
}