#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern int shift;
extern int value;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process every second element in reverse order with stride
    png_uint_32 step = 2;
    png_uint_32 effective_width = (row_width + step - 1) / step;  // Number of elements to process
    png_bytep base_sp = sp - (effective_width - 1) * step;
    png_bytep base_dp = dp - (effective_width - 1) * step;
    shift = 0;  // Reset shift to ensure deterministic behavior across iterations
    for (i = 0; i < effective_width; i++) {
        value = (*(base_sp + i * step) >> shift) & 3;
        *(base_dp + i * step) = (png_byte)value;
        shift = (shift == 6) ? 0 : shift + 2;
    }
}
