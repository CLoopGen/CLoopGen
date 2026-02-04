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
    for (i = 0, rp = row; i < row_width; i += 2, rp += 12) {
        if (i + 1 >= row_width) break;
        png_byte save1 = *rp;
        *rp = *(rp + 4);
        *(rp + 4) = save1;
        save1 = *(rp + 1);
        *(rp + 1) = *(rp + 5);
        *(rp + 5) = save1;

        png_byte save2 = *(rp + 6);
        *(rp + 6) = *(rp + 10);
        *(rp + 10) = save2;
        save2 = *(rp + 7);
        *(rp + 7) = *(rp + 11);
        *(rp + 11) = save2;
    }
}
