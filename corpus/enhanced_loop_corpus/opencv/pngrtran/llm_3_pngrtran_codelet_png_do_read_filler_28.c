#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_uint_32 i;
extern png_uint_32 row_width;
extern png_byte lo_filler;
extern png_bytep sp;
extern png_bytep dp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access – write filler every 3rd position, data every 2nd, creating a strided pattern
    png_uint_32 stride_fill = 3;
    png_uint_32 stride_data = 2;
    png_bytep dp_temp = dp;
    png_bytep sp_temp = sp;
    for (i = 1; i < row_width; i++) {
        *(dp_temp - stride_fill) = lo_filler;
        *(dp_temp - stride_data) = *(sp_temp - 1);
        dp_temp -= 2;
        sp_temp -= 1;
    }
}
