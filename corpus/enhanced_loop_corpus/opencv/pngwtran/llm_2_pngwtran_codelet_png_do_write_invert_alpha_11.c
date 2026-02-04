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



void loop() {
    // Variant 1: Consecutive Memory Access with Offset Indexing
    // Instead of incrementing pointers directly, use base pointer + scaled index
    // to access memory in a more predictable, consecutive pattern.
    png_bytep base = row;
    for (i = 0; i < row_width; i++) {
        png_uint_32 offset = i * 6;
        sp = base + offset;
        dp = sp;
        *(dp + 1) = (png_byte)(255 - *(sp + 2));
        *(dp + 2) = (png_byte)(255 - *(sp + 3));
    }
}
