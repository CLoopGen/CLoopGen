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
    // Variant 1: Consecutive memory access with pre-increment addressing
    // Instead of decrementing dp and conditionally adjusting sp, we process in forward direction
    // by treating dp and sp as incrementing pointers. This changes access pattern to consecutive.
    png_bytep local_sp = sp - (row_width - 1);  // Adjust sp to start at base for forward traversal
    png_bytep local_dp = dp - (row_width - 1);
    int local_shift = shift;

    for (i = 0; i < row_width; i++) {
        if ((*local_sp >> local_shift) & 1)
            *local_dp = 1;
        else
            *local_dp = 0;

        if (local_shift == 7) {
            local_shift = 0;
            local_sp++;
        } else {
            local_shift++;
        }
        local_dp++;
    }
}
