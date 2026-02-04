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
    int temp_v = 0;
    png_uint_32 local_mask = mask;
    png_bytep local_sp = sp;
    png_bytep local_dp = dp;
    for (i = 0; i < row_width; i++) {
        int non_zero = (int)(*local_sp != 0);
        temp_v |= (-non_zero) & local_mask;
        local_sp++;
        if (local_mask > 1) {
            local_mask >>= 1;
        } else {
            *local_dp = (png_byte)temp_v;
            local_dp++;
            temp_v = 0;
            local_mask = 128;
        }
    }
    sp = local_sp;
    dp = local_dp;
    mask = local_mask;
    v = temp_v;
}
