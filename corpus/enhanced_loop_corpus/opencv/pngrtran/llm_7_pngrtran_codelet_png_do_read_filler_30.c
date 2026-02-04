#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_uint_32 i;
extern png_uint_32 row_width;
extern png_byte hi_filler;
extern png_byte lo_filler;
extern png_bytep sp;
extern png_bytep dp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_bytep local_dp = dp;
    png_bytep local_sp = sp;
    png_uint_32 j;
    for (j = 1; j < row_width; j++) {
        *(local_dp - 3) = *(local_sp - 1);
        *(local_dp - 2) = *(local_sp - 2);
        *(local_dp - 1) = hi_filler;
        *(local_dp - 0) = lo_filler;
        local_dp -= 4;
        local_sp -= 2;
    }
    dp = local_dp;
    sp = local_sp;
}
