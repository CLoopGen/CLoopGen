#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_uint_32 i;
extern png_uint_32 row_width;
extern png_byte lo_filler;
extern png_bytep sp;
extern png_bytep dp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access – process every second pixel in reverse, then fill gaps
    png_uint_32 step = 2;
    png_uint_32 effective_width = (row_width + step - 1) / step; // Ceiling division

    for (i = 0; i < effective_width; i++) {
        png_uint_32 rev_idx = row_width - 1 - i * step;

        if (rev_idx < row_width) {
            *(--dp) = lo_filler;
            *(--dp) = (rev_idx + 1 < row_width) ? *(sp - (rev_idx + 1) * 3 + 2) : lo_filler;
            *(--dp) = (rev_idx + 1 < row_width) ? *(sp - (rev_idx + 1) * 3 + 1) : lo_filler;
            *(--dp) = (rev_idx + 1 < row_width) ? *(sp - (rev_idx + 1) * 3 + 0) : lo_filler;

            *(--dp) = lo_filler;
            *(--dp) = *(sp - rev_idx * 3 + 2);
            *(--dp) = *(sp - rev_idx * 3 + 1);
            *(--dp) = *(sp - rev_idx * 3 + 0);
        }
    }

    // Handle any remaining pixel if row_width is odd
    if (row_width % step != 0 && row_width > 1) {
        png_uint_32 last_idx = 0;
        *(--dp) = lo_filler;
        *(--dp) = *(sp - last_idx * 3 + 2);
        *(--dp) = *(sp - last_idx * 3 + 1);
        *(--dp) = *(sp - last_idx * 3 + 0);
    }
}
