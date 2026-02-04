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
    // Variant 2: Strided memory access — process every second element first, then the others (interleaved stride pattern)
    // Simulate strided traversal: first even indices, then odd, with adjusted pointer arithmetic
    png_uint_32 half_width = (row_width + 1) / 2;
    png_bytep sp_start = sp;
    png_bytep dp_start = dp;
    shift = (row_width % 2 == 0) ? 4 : shift; // Adjust initial shift based on effective access order

    // First pass: Stride of 2 starting at 0 (even indices)
    for (i = 0; i < half_width; i++) {
        *dp_start = (png_byte)((*sp_start >> shift) & 15);
        shift = (shift == 4) ? 0 : 4;
        sp_start -= 2;
        dp_start -= 2;
    }

    // Reset pointers for odd-indexed elements (starting one step up from original)
    sp_start = sp - 1;
    dp_start = dp - 1;
    if (row_width > 1) {
        shift = (shift == 4) ? 0 : 4; // Re-sync shift state for second pass continuity
    }

    // Second pass: Stride of 2 starting at 1 (odd indices)
    for (i = 0; i < row_width / 2; i++) {
        *dp_start = (png_byte)((*sp_start >> shift) & 15);
        shift = (shift == 4) ? 0 : 4;
        sp_start -= 2;
        dp_start -= 2;
    }
}
