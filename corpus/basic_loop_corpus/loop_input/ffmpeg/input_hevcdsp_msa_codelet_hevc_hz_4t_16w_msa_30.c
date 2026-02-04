#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int32_t src_stride;
int16_t *dst;
int32_t dst_stride;
int32_t height;
uint32_t loop_cnt;

static uint8_t *src_buffer;
static int16_t *dst_buffer;

void init_vars() {
    const int total_elements_src = 64 * 1024 * 1024; // ~64 MB input
    const int total_elements_dst = 64 * 1024 * 1024; // ~128 MB output (each int16_t is 2 bytes)
    src_stride = 16384; // Stride of 16k bytes for src
    dst_stride = 16384 / sizeof(int16_t); // Stride in int16_t units: 8192 elements
    height = 16384; // Must be divisible by 4 due to >>2 and 4*step

    src_buffer = (uint8_t*)aligned_alloc(32, total_elements_src);
    dst_buffer = (int16_t*)aligned_alloc(32, total_elements_dst * sizeof(int16_t));

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    src = src_buffer;
    dst = dst_buffer;

    for (int i = 0; i < total_elements_src; ++i) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }
    for (int i = 0; i < total_elements_dst; ++i) {
        dst_buffer[i] = (int16_t)(i & 0xFFFF);
    }
}