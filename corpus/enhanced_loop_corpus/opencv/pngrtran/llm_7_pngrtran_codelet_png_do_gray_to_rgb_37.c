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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < row_width; i++) {
        png_byte val_current = *sp;
        png_byte val_prev = *(sp - 1);
        dp[-0] = val_prev;
        dp[-1] = val_prev;
        dp[-2] = val_current;
        dp[-3] = val_current;
        dp[-4] = val_current;
        dp[-5] = val_prev;
        dp -= 6;
        sp--;
    }
}
