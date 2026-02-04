#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep row;
extern int bytes_per_pixel;
extern png_uint_32 row_width;
extern png_bytep rp;
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access - process every second pixel first, then the others (loop fission)
    // Simulates a strided pattern: step through with stride 2, two separate passes
    png_uint_32 step = 2;
    png_bytep base;

    // First pass: even indices (0, 2, 4, ...)
    for (i = 0, base = row; i < row_width; i += step, base += step * bytes_per_pixel) {
        *(base) = (png_byte)(*base - *(base + 1));
        *(base + 2) = (png_byte)(*(base + 2) - *(base + 1));
    }

    // Second pass: odd indices (1, 3, 5, ...) if they exist
    for (i = 1, base = row + bytes_per_pixel; i < row_width; i += step, base += step * bytes_per_pixel) {
        *(base) = (png_byte)(*base - *(base + 1));
        *(base + 2) = (png_byte)(*(base + 2) - *(base + 1));
    }
}
