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
for (i = 0 , rp = row; i < row_width; i++ , rp += 8) {
    png_byte save;
    // Interleaved consecutive access: process two pairs at a time with local grouping
    for (int offset = 0; offset < 2; offset++) {
        save = *(rp + offset);
        *(rp + offset) = *(rp + offset + 4);
        *(rp + offset + 4) = save;
    }
}
}
