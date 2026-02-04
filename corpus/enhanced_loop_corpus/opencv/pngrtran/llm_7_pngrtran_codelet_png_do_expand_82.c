#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern int shift;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_bytep local_sp = sp;
    png_bytep local_dp = dp;
    int local_shift = shift;
    for (i = 0; i < row_width; i++) {
        png_byte source_val = *local_sp;
        png_byte result = ((source_val >> local_shift) & 1) ? 255 : 0;
        *local_dp = result; // Break direct WAW on dp by using local copy
        local_dp--;
        local_shift--;
        if (local_shift < 0) {
            local_shift = 7;
            local_sp--;
        }
    }
    // Write back modified values to globals (reintroduce WAR via final store)
    dp = local_dp;
    sp = local_sp;
    shift = local_shift;
}
