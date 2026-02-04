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
    png_byte local_filler = lo_filler; // Remove direct WAW on lo_filler by using local copy
    png_bytep local_dp = dp;
    png_bytep local_sp = sp;
    png_uint_32 j;

    for (j = 0; j < row_width - 1; j++) {
        *(local_dp - 1) = local_filler;       // Independent write
        *(local_dp - 2) = *(local_sp - 1);    // RAW: read from sp before write to dp
        *(local_dp - 3) = *(local_sp - 2);
        *(local_dp - 4) = *(local_sp - 3);
        local_dp -= 4;
        local_sp -= 3;
    }
    dp = local_dp;  // Update shared pointers only once after loop
    sp = local_sp;
}
