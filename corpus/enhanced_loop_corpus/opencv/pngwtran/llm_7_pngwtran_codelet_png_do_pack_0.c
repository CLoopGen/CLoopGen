#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep sp;
extern png_bytep dp;
extern int mask;
extern int v;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_uint_32 local_i;
    int local_v = v;
    int local_mask = mask;
    png_bytep local_sp = sp;
    png_bytep local_dp = dp;
    for (local_i = 0; local_i < row_width; local_i++) {
        local_v |= (*local_sp != 0) ? local_mask : 0;
        local_sp++;
        local_mask = (local_mask > 1) ? (local_mask >> 1) : 128;
        if (local_mask == 128) {
            *local_dp = (png_byte)local_v;
            local_dp++;
            local_v = 0;
        }
    }
    sp = local_sp;
    dp = local_dp;
    v = local_v;
    mask = local_mask;
}
