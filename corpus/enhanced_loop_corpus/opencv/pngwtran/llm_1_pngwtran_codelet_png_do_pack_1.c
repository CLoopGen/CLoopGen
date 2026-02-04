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
    // Outer loop that splits the iteration space into chunks to increase nesting
    png_uint_32 chunk_size = 8;
    png_uint_32 num_chunks = (row_width + chunk_size - 1) / chunk_size;
    for (png_uint_32 c = 0; c < num_chunks; c++) {
        png_uint_32 start = c * chunk_size;
        png_uint_32 end = (start + chunk_size < row_width) ? start + chunk_size : row_width;
        for (i = start; i < end; i++) {
            png_byte value;
            value = (png_byte)(*sp & 3);
            v |= (value << shift);
            if (shift == 0) {
                shift = 6;
                *dp = (png_byte)v;
                dp++;
                v = 0;
            } else {
                shift -= 2;
            }
            sp++;
        }
    }
}
