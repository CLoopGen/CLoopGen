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
    for (MagickSizeType i = 0; i < 4; i++) {
        for (n = i * bytes_per_pixel * number_pixels; n < (i + 1) * bytes_per_pixel * number_pixels; n++) {
            pixels[n] = 0;
        }
    }
}
