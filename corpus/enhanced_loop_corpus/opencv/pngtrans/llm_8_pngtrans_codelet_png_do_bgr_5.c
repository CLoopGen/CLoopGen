#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep row;
extern png_uint_32 row_width;
extern png_bytep rp;
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0, rp = row; i < row_width - (row_width % 2); i += 2, rp += 6) {
        png_byte save1 = *rp;
        *rp = *(rp + 2);
        *(rp + 2) = save1;

        png_byte save2 = *(rp + 3);
        *(rp + 3) = *(rp + 5);
        *(rp + 5) = save2;
    }
}
