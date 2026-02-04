#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_byte green_high;
extern png_byte blue_high;
extern png_byte red_low;
extern png_byte green_low;
extern png_byte blue_low;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;
extern png_byte red_high;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with step-through pattern
    // Access every second element first, then fill gaps (strided access)
    png_uint_32 half_width = row_width / 2;

    // First pass: process even-indexed pixels (strided by 2)
    for (i = 0; i < half_width; i++) {
        png_byte val1 = *(sp - 5);
        png_byte val2 = *(sp - 3);
        png_byte val3 = *(sp - 1);
        png_byte val4 = *(sp);

        // Only check key channels at strided positions (simulate reduced precision match)
        if (val1 == red_high && val2 == green_high && val3 == blue_high && val4 == blue_low) {
            *dp-- = 0;
            *dp-- = 0;
        } else {
            *dp-- = 255;
            *dp-- = 255;
        }

        *dp-- = val4;
        *dp-- = val3;
        *dp-- = val2;
        *dp-- = *(sp - 4); // Fill skipped
        *dp-- = val1;
        *dp-- = *(sp - 2); // Fill skipped

        sp -= 6;
    }

    // Second pass: handle remainder if row_width is odd
    if (row_width % 2 != 0) {
        i = half_width; // Resume final iteration
        if (*(sp - 5) == red_high && *(sp - 4) == red_low && 
            *(sp - 3) == green_high && *(sp - 2) == green_low && 
            *(sp - 1) == blue_high && *(sp) == blue_low) {
            *dp-- = 0;
            *dp-- = 0;
        } else {
            *dp-- = 255;
            *dp-- = 255;
        }
        *dp-- = *sp--;
        *dp-- = *sp--;
        *dp-- = *sp--;
        *dp-- = *sp--;
        *dp-- = *sp--;
        *dp-- = *sp--;
    }
}
