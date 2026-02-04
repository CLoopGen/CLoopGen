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
uint64_t a = 0xdeadbeefdeadbeefULL;
uint64_t b = 0xc0dec0dec0dec0deULL;

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB of data
static uint16_t src_buffer[DATA_SIZE / sizeof(uint16_t)];

void init_vars() {
    src = src_buffer;
    stride = 1; // ensures we step by one uint16_t per iteration
    i = 0;
    a = 0xdeadbeefdeadbeefULL;
    b = 0xc0dec0dec0dec0deULL;
}