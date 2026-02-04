#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep sp;
extern png_bytep dp;
extern unsigned int shift;
extern int v;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with fixed stride of 4
    // Simulates non-unit stride access pattern, possibly modeling data subsampling or structure field access
    // We assume effective length is reduced accordingly
    int stride = 4;
    png_uint_32 effective_width = row_width / stride + ((row_width % stride) ? 1 : 0);

    for (i = 0; i < effective_width; i++) {
        png_byte value;
        // Access every 4th byte — strided access
        value = (png_byte)(sp[i * stride] & 3);
        v |= (value << shift);
        if (shift == 0) {
            shift = 6;
            *dp = (png_byte)v;
            dp++;
            v = 0;
        } else
            shift -= 2;
    }
    // Update sp to reflect total bytes consumed (not strictly necessary but maintains consistency)
    sp += effective_width * stride;
}
