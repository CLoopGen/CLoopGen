#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
uint32_t loop_cnt;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t total_data_size = 64 << 20; // 64 MB

void init_vars() {
    if (posix_memalign((void**)&src_buffer, 32, total_data_size) != 0) {
        exit(1);
    }
    if (posix_memalign((void**)&dst_buffer, 32, total_data_size) != 0) {
        exit(1);
    }

    for (size_t i = 0; i < total_data_size; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
        dst_buffer[i] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
    stride = 64; 
    loop_cnt = 4;
}