#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_uint_32 row_width;
extern png_bytep sp;
extern png_bytep dp;
extern png_byte save;
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access – process every second pixel first, then odd positions (interleaved pattern)
    png_uint_32 stride = 2;
    png_uint_32 j;

    // Process even indices (conceptually grouped by stride)
    for (j = 0; j < row_width; j += stride) {
        png_byte save_even;
        png_bytep sp_temp = sp - (j + 1) * 4;
        png_bytep dp_temp = dp - (j + 1) * 4;

        save_even = *(--sp_temp);
        *(--dp_temp) = *(--sp_temp);
        *(--dp_temp) = *(--sp_temp);
        *(--dp_temp) = *(--sp_temp);
        *(--dp_temp) = save_even;
    }

    // Process odd indices
    for (j = 1; j < row_width; j += stride) {
        png_byte save_odd;
        png_bytep sp_temp = sp - (j + 1) * 4;
        png_bytep dp_temp = dp - (j + 1) * 4;

        save_odd = *(--sp_temp);
        *(--dp_temp) = *(--sp_temp);
        *(--dp_temp) = *(--sp_temp);
        *(--dp_temp) = *(--sp_temp);
        *(--dp_temp) = save_odd;
    }
}
