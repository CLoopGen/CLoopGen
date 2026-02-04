#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int stride = 4;
int i;
uint8_t *dst;
int16_t *src;

static uint8_t dst_data[256 << 20]; // 256 MB
static int16_t src_data[256 << 19];  // 256 MB / sizeof(int16_t) * 4 per iteration

void init_vars() {
    for (size_t j = 0; j < (256 << 19); j++) {
        src_data[j] = (int16_t)(j & 0x7FFF);
    }
    for (size_t j = 0; j < (256 << 20); j++) {
        dst_data[j] = (uint8_t)(j & 0xFF);
    }
    dst = dst_data;
    src = src_data;
}