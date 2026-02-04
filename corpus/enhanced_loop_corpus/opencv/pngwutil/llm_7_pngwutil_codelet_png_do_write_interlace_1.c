#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern  png_byte png_pass_start[7];
extern  png_byte png_pass_inc[7];
extern png_bytep row;
extern int pass;
extern png_bytep sp;
extern png_bytep dp;
extern unsigned int shift;
extern int d;
extern int value;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_uint_32 k;
    int local_d = 0;
    int local_shift = shift;
    png_bytep local_dp = dp;

    for (k = png_pass_start[pass]; k < row_width; k += png_pass_inc[pass]) {
        sp = row + (size_t)(k >> 3);
        value = (int)(*sp >> (7 - (int)(k & 7))) & 1;

        local_d |= (value << local_shift);

        if (local_shift == 0) {
            *local_dp++ = (png_byte)local_d;
            local_d = 0;
            local_shift = 7;
        } else {
            local_shift--;
        }
    }

    // Update only the outputs that escape the loop
    dp = local_dp;
    d = 0; // Reset main d since accumulation is now local and finalized in buffer
    shift = local_shift;
}
