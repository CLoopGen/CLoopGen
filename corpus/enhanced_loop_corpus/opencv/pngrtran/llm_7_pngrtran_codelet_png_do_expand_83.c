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
    png_uint_32 next_shift;
    png_bytep current_sp;
    for (i = 0; i < row_width; i++) {
        current_sp = sp;
        next_shift = (shift == 6) ? 0 : shift + 2;
        value = (*current_sp >> shift) & 3;
        *dp = (png_byte)(value | (value << 2) | (value << 4) | (value << 6));
        shift = next_shift;
        if (next_shift == 0) sp--;
        dp--;
    }
}
