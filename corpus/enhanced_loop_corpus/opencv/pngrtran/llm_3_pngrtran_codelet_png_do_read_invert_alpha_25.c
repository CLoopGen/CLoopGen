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
    // Variant 2: Strided memory access with alternating read pattern
    // Access source in a non-sequential stride and write two bytes per iteration
    // Simulates a more scattered read pattern while maintaining functional equivalence
    png_bytep temp_sp = sp - row_width * 8;  // Adjust to start of effective data
    png_bytep temp_dp = dp - row_width * 2;

    for (i = 0; i < row_width; i++) {
        png_uint_32 idx1 = i * 8 + 0;
        png_uint_32 idx2 = i * 8 + 4;  // Introduce stride by skipping ahead

        *(temp_dp + i * 2)     = (png_byte)(255 - *(temp_sp + idx1));
        *(temp_dp + i * 2 + 1) = (png_byte)(255 - *(temp_sp + idx2));
    }
}
