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
    // Variant 1: Consecutive memory access by precomputing effective indices and accessing sp and dp in increasing order
    png_bytep sp_base = sp - row_width + 1;  // Adjust sp to start from the effective beginning
    png_bytep dp_base = dp - row_width + 1;  // Same for dp
    png_uint_32 current_shift = (shift == 4) ? 4 : 0; // Initial shift state inferred from input

    for (i = 0; i < row_width; i++) {
        png_bytep current_sp = sp_base + i;
        *dp_base = (png_byte)((*current_sp >> current_shift) & 15);
        if (current_shift == 4) {
            current_shift = 0;
        } else {
            current_shift = 4;
            sp_base--; // Compensate extra sp step when shift resets
        }
        dp_base++;
    }
}
