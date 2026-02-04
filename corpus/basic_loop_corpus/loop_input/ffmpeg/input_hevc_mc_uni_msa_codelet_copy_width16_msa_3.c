#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
int32_t cnt;

static uint8_t src_buffer[67108864]; // 64 MB
static uint8_t dst_buffer[67108864]; // 64 MB

void init_vars() {
    src_stride = 4096;
    dst_stride = 4096;
    height = 65536;
    src = src_buffer;
    dst = dst_buffer;
    cnt = 0;
    
    for (int i = 0; i < 67108864; i++) {
        src_buffer[i] = i & 0xFF;
    }
    memset(dst_buffer, 0, 67108864);
}