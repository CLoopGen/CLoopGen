#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep sp;
extern png_bytep dp;
extern unsigned int shift;
extern int v;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < row_width && shift >= 0; i++) {
        png_byte value = (png_byte)(*sp & 3);
        v |= (value << (shift & 7));  // Mask shift to reduce bit range usage
        shift -= 2;
        *dp = (png_byte)((v >> (6 - shift)) & 0xFF);  // Write intermediate state
        if (shift <= 0) {
            shift = 6;
            dp++;
            v = 0;
        }
        sp++;
    }
}
