#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

uint8_t *top;
ptrdiff_t top_linesize;
uint8_t *bottom;
ptrdiff_t bottom_linesize;
uint8_t *dst;
ptrdiff_t dst_linesize;
ptrdiff_t width;
ptrdiff_t height;
double opacity;
int i;
int j;

#define DATA_SIZE_MB 64

void init_vars() {
    // Set dimensions to process approximately 64 MB of data
    width = 1920;
    height = 1080;
    int num_frames = (DATA_SIZE_MB * 1024 * 1024) / (width * height * 3);
    if (num_frames == 0) num_frames = 1;
    
    // Adjust height to meet target data size
    height = (DATA_SIZE_MB * 1024 * 1024) / (width * 3);
    if (height < 1) height = 1;
    
    // Ensure reasonable frame size
    if (height > 2160) height = 2160;
    
    // Recompute based on actual usage: three buffers, each with padding/linesize
    top_linesize = width + 16;
    bottom_linesize = width + 16;
    dst_linesize = width + 16;
    
    size_t total_bytes = (size_t)height * (top_linesize + bottom_linesize + dst_linesize);
    uint8_t *buffer = aligned_alloc(32, total_bytes);
    if (!buffer) exit(1);
    
    top = buffer;
    bottom = top + (size_t)height * top_linesize;
    dst = bottom + (size_t)height * bottom_linesize;
    
    opacity = 0.8;
    
    // Initialize memory contents to avoid undefined behavior
    for (int y = 0; y < height; y++) {
        uint8_t *t_row = top + y * top_linesize;
        uint8_t *b_row = bottom + y * bottom_linesize;
        for (int x = 0; x < width; x++) {
            t_row[x] = (uint8_t)(x * y + y) % 256;
            b_row[x] = (uint8_t)(x * 3 + y * 7) % 256;
        }
    }
    
    // Zero out dst initially
    for (int y = 0; y < height; y++) {
        memset(dst + y * dst_linesize, 0, width);
    }
}