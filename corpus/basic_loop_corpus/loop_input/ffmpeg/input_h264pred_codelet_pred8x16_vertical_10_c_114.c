#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint64_t u64;
    uint32_t u32[2];
    uint16_t u16[4];
    uint8_t u8[8];
    double f64;
    float f32[2];
} av_alias64;

int i;
uint16_t *src;
int stride;
uint64_t a;
uint64_t b;

#define DATA_SIZE (16 * 1024 * 1024) // 16MB to ensure ~0.01s runtime
static uint16_t src_data[DATA_SIZE];

void init_vars() {
    a = 0x1122334455667788ULL;
    b = 0x99AABBCCDDEEFF00ULL;
    stride = 8; // ensures we don't overflow within 16 iterations with 16MB data
    src = src_data;
    i = 0;
}