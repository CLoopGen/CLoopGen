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
    // Variant 2: Strided memory access — write every 'stride'-th byte first,
    // effectively traversing memory with a stride equal to '4 * bytes_per_pixel'.
    // This mimics a more scattered access pattern, possibly modeling planar layout.
    size_t stride = 4 * bytes_per_pixel;
    for (size_t b = 0; b < stride; b++) {
        for (n = 0; n < number_pixels; n++) {
            pixels[b + stride * n] = 0;
        }
    }
}
