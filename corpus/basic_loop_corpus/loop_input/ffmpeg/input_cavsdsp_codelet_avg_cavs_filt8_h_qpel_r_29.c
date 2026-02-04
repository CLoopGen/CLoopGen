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
ptrdiff_t dstStride;
ptrdiff_t srcStride;
int h;
uint8_t *cm;
int i;

void init_vars() {
    const int width = 8;
    const int filter_tap = 6; // accesses from src[-2] to src[10] -> total span 13, but center at -2..+10
    const int src_padding = 12; // need up to src[-2] and src[10], so pad at least 10 forward and 2 backward
    const int row_size = width + src_padding;
    const int total_rows = TOTAL_PIXELS / row_size;
    
    srcStride = row_size;
    dstStride = width;

    h = total_rows;

    src = aligned_alloc(STRIDE_ALIGN, total_rows * srcStride * sizeof(uint8_t));
    dst = aligned_alloc(STRIDE_ALIGN, total_rows * dstStride * sizeof(uint8_t));
    cm = aligned_alloc(STRIDE_ALIGN, 256 * sizeof(uint8_t));

    if (!src || !dst || !cm) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int y = 0; y < total_rows; y++) {
        uint8_t* s_row = src + y * srcStride;
        uint8_t* d_row = dst + y * dstStride;
        for (int x = 0; x < width; x++) {
            d_row[x] = rand() % 256;
            s_row[x + 2] = rand() % 256; // offset by 2 to allow -2 index
        }
        // Fill padding areas (-2 to +10 relative to valid window)
        for (int x = 0; x < 2; x++) {
            s_row[x] = s_row[2]; // replicate boundary
        }
        for (int x = width + 2; x < width + src_padding; x++) {
            s_row[x] = s_row[width + 1]; // replicate end
        }
    }

    for (int j = 0; j < 256; j++) {
        cm[j] = (uint8_t)(rand() % 256);
    }
}