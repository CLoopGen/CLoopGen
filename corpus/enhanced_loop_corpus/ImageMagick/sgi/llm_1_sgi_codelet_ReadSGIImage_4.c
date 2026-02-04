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
    if (bytes_per_pixel == 0 || number_pixels == 0) return;
    for (MagickSizeType outer = 0; outer < bytes_per_pixel; outer++) {
        for (n = 0; n < (4 * number_pixels); n++) {
            pixels[4 * outer * number_pixels + n] = 0;
        }
    }
}
