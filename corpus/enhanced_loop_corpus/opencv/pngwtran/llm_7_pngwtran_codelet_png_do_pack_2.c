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
    png_byte local_v = 0;
    unsigned int local_shift = shift;
    png_bytep local_sp = sp;
    png_bytep local_dp = dp;
    for (i = 0; i < row_width; i++) {
        png_byte value = (png_byte)(*local_sp & 15);
        local_v |= (value << local_shift);
        if (local_shift == 0) {
            *local_dp = local_v;
            local_dp++;
            local_v = 0;
            local_shift = 4;
        } else {
            local_shift -= 4;
        }
        local_sp++;
    }
    sp = local_sp;
    dp = local_dp;
    v = local_v;
    shift = local_shift;
}
