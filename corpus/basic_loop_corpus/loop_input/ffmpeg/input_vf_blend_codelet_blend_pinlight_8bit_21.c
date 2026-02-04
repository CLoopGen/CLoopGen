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

static uint8_t *alloc_aligned_size(ptrdiff_t rows, ptrdiff_t cols) {
    size_t size = (size_t)rows * (size_t)cols;
    uint8_t *ptr = aligned_alloc(32, size);
    if (!ptr) exit(1);
    return ptr;
}

void init_vars() {
    width = 1920;
    height = 1080;
    
    double target_time_per_pixel = 0.01 / (width * height);
    size_t total_pixels = (size_t)width * (size_t)height;
    size_t target_total_pixels = (size_t)(0.01 / target_time_per_pixel);
    
    if (total_pixels < target_total_pixels) {
        double scale = sqrt((double)target_total_pixels / total_pixels);
        width = (ptrdiff_t)(width * scale);
        height = (ptrdiff_t)(height * scale);
    }
    
    top_linesize = width + 32;
    bottom_linesize = width + 32;
    dst_linesize = width + 32;
    
    top = alloc_aligned_size(height, top_linesize);
    bottom = alloc_aligned_size(height, bottom_linesize);
    dst = alloc_aligned_size(height, dst_linesize);
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            top[y * top_linesize + x] = (uint8_t)((x * y) % 256);
            bottom[y * bottom_linesize + x] = (uint8_t)((x + y) % 256);
        }
    }
    
    opacity = 0.5;
    i = 0;
    j = 0;
}