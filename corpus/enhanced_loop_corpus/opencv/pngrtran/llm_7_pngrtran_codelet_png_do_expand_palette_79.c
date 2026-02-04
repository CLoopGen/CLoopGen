#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern int shift;
extern int value;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_uint_32 local_shift = shift;
    png_bytep local_sp = sp;
    png_bytep local_dp = dp;
    for (i = 0; i < row_width; i++) {
        png_uint_32 extracted = (*local_sp >> local_shift) & 15;
        *(local_dp) = (png_byte)extracted;
        local_shift += 4;
        if (local_shift >= 8) {
            local_shift = 0;
            local_sp--;
        }
        local_dp--;
    }
    shift = local_shift;
    sp = local_sp;
    dp = local_dp;
}
