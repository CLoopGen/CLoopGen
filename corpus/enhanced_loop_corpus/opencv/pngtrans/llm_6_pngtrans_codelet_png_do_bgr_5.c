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
    png_byte temp;
    for (i = 0, rp = row; i < row_width; i++, rp += 3) {
        temp = *rp;
        *(rp + 1) = temp + *(rp + 2); // Introduce RAW dependency: use of *rp and *(rp+2) before write to *(rp+1)
        *rp = *(rp + 2);
        *(rp + 2) = temp;
    }
}
