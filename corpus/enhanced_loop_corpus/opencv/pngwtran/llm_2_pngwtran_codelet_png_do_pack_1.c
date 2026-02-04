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
    // Variant 1: Consecutive memory access with unrolled loop (factor of 2)
    // This variant assumes row_width is even for simplicity and accesses sp in strides of 2
    // to enable consecutive reads and improve cache locality.
    png_uint_32 end = row_width - (row_width % 2); // Make it even
    for (i = 0; i < end; i += 2) {
        png_byte value1, value2;
        value1 = (png_byte)(sp[0] & 3);
        value2 = (png_byte)(sp[1] & 3);

        v |= (value1 << shift);
        if (shift == 0) {
            *dp = (png_byte)v;
            dp++;
            v = 0;
            shift = 6;
        } else {
            shift -= 2;
        }

        v |= (value2 << shift);
        if (shift == 0) {
            *dp = (png_byte)v;
            dp++;
            v = 0;
            shift = 6;
        } else {
            shift -= 2;
        }

        sp += 2;
    }
    // Handle remaining element if row_width is odd
    for (; i < row_width; i++) {
        png_byte value;
        value = (png_byte)(*sp & 3);
        v |= (value << shift);
        if (shift == 0) {
            shift = 6;
            *dp = (png_byte)v;
            dp++;
            v = 0;
        } else
            shift -= 2;
        sp++;
    }
}
