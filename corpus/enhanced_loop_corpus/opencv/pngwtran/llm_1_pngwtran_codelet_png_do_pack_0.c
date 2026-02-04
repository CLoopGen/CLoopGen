#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep sp;
extern png_bytep dp;
extern int mask;
extern int v;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_uint_32 outer, inner;
    png_uint_32 block_size = 8;
    png_uint_32 num_blocks = (row_width + block_size - 1) / block_size;

    for (outer = 0; outer < num_blocks; outer++) {
        for (inner = 0; inner < block_size; inner++) {
            png_uint_32 i = outer * block_size + inner;
            if (i >= row_width) break;

            if (*sp != 0)
                v |= mask;
            sp++;
            if (mask > 1) {
                mask >>= 1;
            } else {
                mask = 128;
                *dp = (png_byte)v;
                dp++;
                v = 0;
            }
        }
    }
}
