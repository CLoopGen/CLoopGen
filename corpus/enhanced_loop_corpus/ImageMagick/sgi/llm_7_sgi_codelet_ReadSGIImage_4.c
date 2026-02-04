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
    MagickSizeType stride = 4 * bytes_per_pixel;
    MagickSizeType i;
    for (i = 0; i < number_pixels; i++) {
        MagickSizeType base = i * stride;
        pixels[base] = 0;
        pixels[base + 1] = 0;
        pixels[base + 2] = 0;
        pixels[base + 3] = 0;
    }
}
