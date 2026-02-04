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

#define DATA_SIZE_MB 64
#define TOTAL_BYTES (DATA_SIZE_MB * 1024 * 1024)

static uint8_t src_data[TOTAL_BYTES];
static uint8_t dst_data[TOTAL_BYTES];

void init_vars() {
    const int block_height = 2;
    const int dst_channels = 3;
    const int src_step = 1;
    const int dst_step = 3;
    
    width = 1024;
    src_stride = width * src_step;
    dst_stride = width * dst_channels;
    
    size_t src_size = block_height * src_stride;
    size_t dst_size = block_height * dst_stride;
    
    if (src_size > sizeof(src_data) || dst_size > sizeof(dst_data)) {
        fprintf(stderr, "Buffer size too small\n");
        exit(1);
    }
    
    src = src_data;
    dst = dst_data;
    
    for (int y = 0; y < block_height; y++) {
        for (int x = 0; x < width; x++) {
            src[y * src_stride + x] = rand() & 0xFF;
        }
    }
    
    for (int y = 0; y < block_height; y++) {
        for (int x = 0; x < width * dst_channels; x++) {
            dst[y * dst_stride + x] = 0;
        }
    }
}