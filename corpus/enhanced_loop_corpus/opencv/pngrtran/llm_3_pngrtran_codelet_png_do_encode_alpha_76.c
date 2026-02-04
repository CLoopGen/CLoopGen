#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

typedef unsigned short png_uint_16;

typedef png_uint_16 **png_uint_16pp;

extern png_bytep row;
extern png_uint_32 row_width;
extern png_uint_16pp table;
extern int gamma_shift;
extern int step;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided access pattern with reversed iteration and stride applied on table index
    png_uint_32 idx;
    png_bytep r = row;
    int g_shift = gamma_shift;
    int s = step;

    // Reverse the order of processing: iterate from last element to first
    for (idx = 0; idx < row_width; ++idx, r -= s) {
        png_uint_32 offset = (row_width - idx - 1) * s;
        png_bytep current = row + offset;
        png_uint_16 v;

        // Strided read: use alternating or non-unit stride in source data interpretation
        v = table[(*(current + 1) >> g_shift) ^ (offset & 1)] [*current]; // Induce strided table row selection

        *current = (png_byte)((v >> 8) & 255);
        *(current + 1) = (png_byte)(v & 255);
    }
}
