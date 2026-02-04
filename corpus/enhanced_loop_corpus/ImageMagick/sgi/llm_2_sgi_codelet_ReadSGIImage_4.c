#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned long long MagickSizeType;

extern MagickSizeType n;
extern MagickSizeType number_pixels;
extern size_t bytes_per_pixel;
extern unsigned char *pixels;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by processing one pixel at a time,
    // each pixel consisting of 'bytes_per_pixel' consecutive bytes.
    // This improves spatial locality and may aid cache performance.
    MagickSizeType total_pixels = number_pixels;
    size_t step = bytes_per_pixel;
    for (n = 0; n < total_pixels; n++) {
        MagickSizeType base_index = 4 * n * step;
        for (size_t b = 0; b < step; b++) {
            pixels[base_index + b] = 0;
        }
    }
}
