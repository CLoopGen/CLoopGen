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
    // Variant 2: Strided memory access – process every second element first, then the others
    // Simulates cache-unfriendly or tiled-like access pattern by striding
    // Two-pass strided write: even indices, then odd indices with step size 2
    png_bytep temp_sp = sp;
    int local_shift = shift;

    // First pass: indices where (i % 2) == 0
    for (i = 0; i < row_width; i += 2) {
        value = (*(temp_sp - (i / 2)) >> local_shift) & 15;
        *dp = (png_byte)value;
        local_shift = (local_shift == 4) ? 0 : local_shift + 4;
        dp--;
    }

    local_shift = (local_shift == 4) ? 0 : local_shift;
    temp_sp = sp;

    // Second pass: indices where (i % 2) == 1
    for (i = 1; i < row_width; i += 2) {
        value = (*(temp_sp - ((i - 1) / 2)) >> local_shift) & 15;
        *dp = (png_byte)value;
        local_shift = (local_shift == 4) ? 0 : local_shift + 4;
        dp--;
    }
}
