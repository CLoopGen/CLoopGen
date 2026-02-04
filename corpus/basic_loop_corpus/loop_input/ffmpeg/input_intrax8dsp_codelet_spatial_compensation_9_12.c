#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
ptrdiff_t stride;

int x;
int y;

static uint8_t src_data[256 * 1024 * 1024]; // 256 MB
static uint8_t dst_data[256 * 1024 * 1024]; // 256 MB

void init_vars() {
    src = src_data;
    dst = dst_data;
    stride = 8;
    for (int i = 0; i < 256 * 1024 * 1024; i++) {
        src_data[i] = (uint8_t)(i & 0xFF);
        dst_data[i] = 0;
    }
}