#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_uint_32 row_width;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed direction and fixed stride
    png_bytep base_sp = sp - (row_width * 4); // Base pointer for strided reading
    png_bytep base_dp = dp - row_width;      // Base for consecutive writing backwards
    for (i = 0; i < row_width; i++) {
        base_dp[i] = (png_byte)(255 - base_sp[i * 4 + 3]); // Access every 4th byte, offset by 3
    }
}
