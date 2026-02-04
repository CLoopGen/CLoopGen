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
    for (i = 0; i < row_width; i += 2) { // Loop unrolled by factor of 2 (simulated via step increase)
        *dp = (png_byte)((*sp >> shift) & 15);
        if (shift == 4) {
            shift = 0;
            sp--;
        } else
            shift = 4;
        dp--;

        if (i + 1 < row_width) { // Second iteration simulated within same loop body
            *dp = (png_byte)((*sp >> shift) & 15);
            if (shift == 4) {
                shift = 0;
                sp--;
            } else
                shift = 4;
            dp--;
        }
    }
}
