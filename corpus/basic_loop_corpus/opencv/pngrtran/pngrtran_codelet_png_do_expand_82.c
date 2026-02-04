#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern int shift;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < row_width; i++) {
    if ((*sp >> shift) & 1)
        *dp = 255;
    else
        *dp = 0;
    if (shift == 7) {
        shift = 0;
        sp--;
    } else
        shift++;
    dp--;
}

}
