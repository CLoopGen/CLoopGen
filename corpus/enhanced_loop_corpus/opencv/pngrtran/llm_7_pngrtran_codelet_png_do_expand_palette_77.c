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
        // Remove write-read dependency on dp by using temporary
        png_byte result;
        if ((*local_sp >> local_shift) & 1)
            result = 1;
        else
            result = 0;

        local_shift++;
        if (local_shift == 8) {
            local_shift = 0;
            local_sp--; // Decrement source pointer every 8 shifts
        }

        *(--local_dp) = result; // Write result in decoupled manner
    }
    // Carry out final updates to globals
    shift = local_shift;
    sp = local_sp;
    dp = local_dp;
}
