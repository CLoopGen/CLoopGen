#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int w;
int h;
uint8_t *cm;
int i;
int j;

static uint8_t *dst_buffer;
static uint8_t *src_buffer;
static uint8_t *cm_buffer;

void init_vars() {
    w = 1024;
    h = 1024;
    srcStride = w + 2; 
    dstStride = w;
    
    size_t src_size = (size_t)(h + 2) * srcStride;
    size_t dst_size = (size_t)h * dstStride;
    size_t cm_size = 512;
    
    src_buffer = aligned_alloc(32, src_size * sizeof(uint8_t));
    dst_buffer = aligned_alloc(32, dst_size * sizeof(uint8_t));
    cm_buffer = aligned_alloc(32, cm_size * sizeof(uint8_t));
    
    src = src_buffer + srcStride * 1 + 1;
    dst = dst_buffer;
    
    for (size_t idx = 0; idx < src_size; idx++) {
        src_buffer[idx] = rand() & 0xFF;
    }
    for (size_t idx = 0; idx < dst_size; idx++) {
        dst_buffer[idx] = rand() & 0xFF;
    }
    for (size_t idx = 0; idx < cm_size; idx++) {
        cm_buffer[idx] = rand() & 0x7F;
    }
    
    cm = cm_buffer + 256;
    
    i = 0;
    j = 0;
}