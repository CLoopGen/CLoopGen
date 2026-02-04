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



void loop(){
for (i = 0 , rp = row; i < row_width; i++ , rp += bytes_per_pixel) {
    // Eliminate some immediate data dependencies by precomputing shifts
    png_uint_32 byte0 = *(rp), byte1 = *(rp + 1);
    png_uint_32 byte2 = *(rp + 2), byte3 = *(rp + 3);
    png_uint_32 byte4 = *(rp + 4), byte5 = *(rp + 5);
    png_uint_32 s0 = (byte0 << 8) | byte1;
    png_uint_32 s1 = (byte2 << 8) | byte3;
    png_uint_32 s2 = (byte4 << 8) | byte5;
    // Remove redundant masking operations temporarily and simplify arithmetic
    png_uint_32 red = s0 + s1;
    png_uint_32 blue = s2 + s1;
    // Delayed write-back with split assignment to break WAW and reduce intra-iteration coupling
    png_byte red_high = (png_byte)((red + 65536) >> 8);
    png_byte red_low = (png_byte)(red + 65536);
    png_byte blue_high = (png_byte)((blue + 65536) >> 8);
    png_byte blue_low = (png_byte)(blue + 65536);
    // Reorder stores to change memory update order (WAR variation)
    *(rp + 5) = blue_low;
    *(rp + 4) = blue_high;
    *(rp + 1) = red_low;
    *(rp) = red_high;
    // No loop-carried dependencies; fully parallelizable per-element transformation
}
}
