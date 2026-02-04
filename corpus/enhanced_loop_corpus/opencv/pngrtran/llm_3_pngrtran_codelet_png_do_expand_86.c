#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;
extern unsigned int gray_high;
extern unsigned int gray_low;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access – process every second element in a forward pass, simulate striding
    png_bytep sp_local = sp - (row_width - 1) * 2; // Adjust to start of effective data considering stride
    png_bytep dp_local = dp - (row_width - 1) * 4; // Each iteration writes 4 bytes, reads 2
    png_uint_32 i_local = 0;

    for (i_local = 0; i_local < row_width; i_local++) {
        png_byte prev_val = *(sp_local + i_local * 2 - 1);
        png_byte curr_val = *(sp_local + i_local * 2);

        if ((prev_val & 255U) == gray_high && (curr_val & 255U) == gray_low) {
            *(dp_local + i_local * 4 + 0) = 0;
            *(dp_local + i_local * 4 + 1) = 0;
        } else {
            *(dp_local + i_local * 4 + 0) = 255;
            *(dp_local + i_local * 4 + 1) = 255;
        }
        *(dp_local + i_local * 4 + 2) = *(sp_local + i_local * 2 + 0);
        *(dp_local + i_local * 4 + 3) = *(sp_local + i_local * 2 + 1);
    }

    // Update global pointers after forward processing
    sp -= row_width * 2;
    dp -= row_width * 4;
}
