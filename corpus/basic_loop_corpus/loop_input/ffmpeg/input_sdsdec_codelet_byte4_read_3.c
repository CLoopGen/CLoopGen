#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint32_t *dst;
int i;

static uint8_t src_buffer[134217728]; // 128 MB buffer
static uint32_t dst_buffer[33554432]; // 128 MB / 4 = 32M elements

void init_vars() {
    src = src_buffer;
    dst = dst_buffer;
    for (size_t idx = 0; idx < 134217728; ++idx) {
        src[idx] = (uint8_t)(idx & 0xFF);
    }
    for (size_t idx = 0; idx < 33554432; ++idx) {
        dst[idx] = 0;
    }
}