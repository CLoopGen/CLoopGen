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
    MagickSizeType i;
    for (i = 0; i < number_pixels; i++) {
        size_t pixel_offset = i * bytes_per_pixel;
        for (size_t j = 0; j < 4; j++) {
            pixels[4 * pixel_offset + j] = 0;
        }
    }
}
