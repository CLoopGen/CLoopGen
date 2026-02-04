#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_uint_32 i;
extern png_uint_32 row_width;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 shift;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_uint_32 local_shift = shift;
    png_bytep local_sp = sp;
    png_bytep local_dp = dp;
    for (i = 0; i < row_width; i++) {
        *(local_dp--) = (png_byte)((*local_sp >> local_shift) & 1);
        local_shift = (local_shift + 1) & 7;
        if ((local_shift & 7) == 0) {
            local_sp--;
        }
    }
    shift = local_shift;
    dp = local_dp;
    sp = local_sp;
}
