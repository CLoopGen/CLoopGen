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
    // Variant 2: Strided memory access – process every second element in reverse, then fill gaps
    png_uint_32 step = 2;
    png_bytep temp_sp = sp;
    png_bytep temp_dp = dp;
    png_uint_32 temp_shift = shift;

    // First pass: strided access (every 2nd element)
    for (i = 0; i < row_width; i += step) {
        *temp_dp = (png_byte)((*temp_sp >> temp_shift) & 3);
        if (temp_shift == 6) {
            temp_shift = 0;
            temp_sp -= 2;  // Larger jump on source
        } else {
            temp_shift += 2;
        }
        temp_dp -= 2;  // Strided write
    }

    // Second pass: fill in the intermediate elements with sequential behavior
    temp_shift = (shift + ((row_width / 2) * 2)) % 8;  // Predict shift state after first pass
    temp_sp = sp - (row_width / 2);  // Adjust source offset
    temp_dp = dp - 1;                // Start at first odd index

    for (i = 1; i < row_width; i += step) {
        *temp_dp = (png_byte)((*temp_sp >> temp_shift) & 3);
        if (temp_shift == 6) {
            temp_shift = 0;
            temp_sp--;
        } else {
            temp_shift += 2;
        }
        temp_dp -= 2;
    }

    // Update globals to reflect final state
    shift = temp_shift;
    sp = temp_sp;
    dp = temp_dp;
}
