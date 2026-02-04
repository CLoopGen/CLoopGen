#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int src_stride;
uint8_t *dst;
int dst_stride;
int width;
int i;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t total_src_size;
static size_t total_dst_size;

void init_vars() {
    width = 1024;
    src_stride = width + 4;
    dst_stride = width * 3;
    
    total_src_size = (size_t)(width + 4) * (width + 4);
    total_dst_size = (size_t)width * width * 3;
    
    src_buffer = (uint8_t*)aligned_alloc(32, total_src_size);
    dst_buffer = (uint8_t*)aligned_alloc(32, total_dst_size);
    
    if (!src_buffer || !dst_buffer) {
        exit(1);
    }
    
    for (size_t idx = 0; idx < total_src_size; idx++) {
        src_buffer[idx] = (uint8_t)(idx % 256);
    }
    
    for (size_t idx = 0; idx < total_dst_size; idx++) {
        dst_buffer[idx] = 0;
    }
    
    src = src_buffer + (2 * src_stride + 2);
    dst = dst_buffer;
}