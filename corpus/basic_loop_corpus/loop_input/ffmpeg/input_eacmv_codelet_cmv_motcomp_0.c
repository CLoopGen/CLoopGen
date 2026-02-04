#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned char *dst;
ptrdiff_t dst_stride;
unsigned char *src;
ptrdiff_t src_stride;
int x;
int y;
int xoffset;
int yoffset;
int width;
int height;
int i;
int j;

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB total data size

void init_vars() {
    // Set dimensions to ensure safe access within bounds
    width = 8192;
    height = 8192;
    
    // Choose a region that ensures the loop accesses valid memory
    x = 100;
    y = 100;
    xoffset = -50;
    yoffset = -50;
    
    // Ensure the loop over [x, x+4) and [y, y+4) with offset stays in bounds
    // i+xoffset in [50, 150), j+yoffset in [50, 150) which is within [0, width/height)
    
    // Strides are chosen to be slightly larger than width for realism
    dst_stride = width + 32;
    src_stride = width + 32;
    
    // Allocate large buffers to make loop take ~0.01s due to cache effects and memory traffic
    dst = (unsigned char*)aligned_alloc(32, dst_stride * (size_t)height);
    src = (unsigned char*)aligned_alloc(32, src_stride * (size_t)height);
    
    // Initialize src with non-zero data to make effect observable
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            src[row * src_stride + col] = (unsigned char)((row ^ col) & 0xFF);
        }
    }
    
    // Initialize dst to zero
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            dst[row * dst_stride + col] = 0;
        }
    }
}