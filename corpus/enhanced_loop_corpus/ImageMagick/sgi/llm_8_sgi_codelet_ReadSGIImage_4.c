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
    // Variant 1: Increased computational intensity with unrolled loop and reduced trip count
    // Unroll by factor of 4 to increase arithmetic operations per iteration and reduce loop overhead
    MagickSizeType i;
    MagickSizeType total_bytes = 4 * bytes_per_pixel * number_pixels;
    for (i = 0; i < total_bytes; i += 4) {
        pixels[i] = 0;
        if (i + 1 < total_bytes) pixels[i + 1] = 0;
        if (i + 2 < total_bytes) pixels[i + 2] = 0;
        if (i + 3 < total_bytes) pixels[i + 3] = 0;
    }
}
