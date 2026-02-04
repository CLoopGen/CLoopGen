#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int w;
int h;
uint8_t *cm;
int i;
int j;

#define DATA_SIZE_MB 64

static uint8_t *alloc_aligned(size_t size) {
    void *ptr;
    if (posix_memalign(&ptr, 32, size) != 0) {
        exit(1);
    }
    return (uint8_t*)ptr;
}

void init_vars() {
    w = 2048;
    h = 8192 / 4;
    
    srcStride = w + 8;
    dstStride = w + 8;
    
    size_t src_size = (size_t)(h + 4) * srcStride;
    size_t dst_size = (size_t)(h + 2) * dstStride;
    size_t cm_size = 256;
    
    src = alloc_aligned(src_size);
    dst = alloc_aligned(dst_size);
    cm = alloc_aligned(cm_size);
    
    for (size_t idx = 0; idx < src_size; idx++) {
        src[idx] = rand() & 0xFF;
    }
    for (size_t idx = 0; idx < dst_size; idx++) {
        dst[idx] = rand() & 0xFF;
    }
    for (size_t idx = 0; idx < cm_size; idx++) {
        cm[idx] = idx;
    }
    
    i = 0;
    j = 0;
}