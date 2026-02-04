#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;
extern unsigned int gray;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (process every 2nd element in reverse, then fill gaps)
    png_uint_32 step = 2;
    png_bytep sp_even = sp;
    png_bytep dp_even = dp;
    png_uint_32 effective_width = (row_width + step - 1) / step;

    // First pass: process elements at even indices (in reverse order of original array)
    for (i = 0; i < effective_width; i++) {
        png_uint_32 idx = row_width - 1 - i * step;  // Reverse strided index
        if (idx < row_width) {
            png_byte val = sp_even[-(ptrdiff_t)(row_width - 1 - idx)];
            if ((val & 255U) == gray)
                *dp_even-- = 0;
            else
                *dp_even-- = 255;
            *dp_even-- = val;
        }
    }

    // Second pass: handle remaining elements (odd indices) if any
    for (i = 0; i < effective_width; i++) {
        png_uint_32 idx = row_width - 1 - (i * step + 1);
        if (idx < row_width) {
            png_byte val = sp_even[-(ptrdiff_t)(row_width - 1 - idx)];
            if ((val & 255U) == gray)
                *dp_even-- = 0;
            else
                *dp_even-- = 255;
            *dp_even-- = val;
        }
    }
    sp = sp_even - row_width + 1;
    dp = dp_even;
}
