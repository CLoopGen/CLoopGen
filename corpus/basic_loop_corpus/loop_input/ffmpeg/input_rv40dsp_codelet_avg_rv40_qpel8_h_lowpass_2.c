#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define DATA_SIZE_MB 64
#define TOTAL_PIXELS (DATA_SIZE_MB * 1024 * 1024)
#define STRIDE_ALIGN 64

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int h;
int C1 = 8;
int C2 = 4;
int SHIFT = 6;
uint8_t *cm;

int i;

void init_vars() {
    const int block_height = 1024;
    const int block_width = 16;
    
    srcStride = (block_width + 12) + STRIDE_ALIGN - ((block_width + 12) % STRIDE_ALIGN);
    dstStride = block_width + STRIDE_ALIGN - (block_width % STRIDE_ALIGN);
    h = block_height;

    size_t src_size = (size_t)(srcStride) * h + 12;
    size_t dst_size = (size_t)(dstStride) * h;
    size_t cm_size = 512;

    src = aligned_alloc(STRIDE_ALIGN, src_size);
    dst = aligned_alloc(STRIDE_ALIGN, dst_size);
    cm = aligned_alloc(STRIDE_ALIGN, cm_size);

    if (!src || !dst || !cm) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < src_size; i++) {
        src[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < dst_size; i++) {
        dst[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < cm_size; i++) {
        cm[i] = rand() & 0x7F;
    }

    i = 0;
}