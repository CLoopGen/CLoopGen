#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned long long MagickSizeType;

MagickSizeType n;
MagickSizeType number_pixels = 65536; // 65536 pixels
size_t bytes_per_pixel = 4;
unsigned char *pixels;

void init_vars() {
    pixels = (unsigned char *)calloc(4 * bytes_per_pixel * number_pixels, sizeof(unsigned char));
    if (!pixels) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}