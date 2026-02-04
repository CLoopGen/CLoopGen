#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep row;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with fixed stride of 2, simulating a transposed or interleaved layout
    // We reinterpret the data as being accessed in a strided manner where even indices hold one channel,
    // and odd indices another. The swap now occurs across strides.
    png_bytep base = row;
    png_uint_32 stride = 2;

    for (i = 0; i < row_width; i += 2) {
        png_byte save = base[i * stride];           // Even index: original sp[0], sp[2], ...
        base[i * stride + 1] = base[(i + 1) * stride]; // dp gets next element from strided view
        base[(i + 1) * stride + 1] = save;
    }
}
