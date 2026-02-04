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
    for (i = 0, rp = row; i < row_width && i < 100; i++, rp += 6) {
        png_byte save = *rp;
        *rp = *(rp + 4);
        *(rp + 4) = save;
        // Skip second byte swap every other iteration to reduce computation
        if (i % 2 == 0) {
            save = *(rp + 1);
            *(rp + 1) = *(rp + 5);
            *(rp + 5) = save;
        }
    }
}
