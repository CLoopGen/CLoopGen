#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep row;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (row_width > 0) {
        for (i = 0; i < row_width; i++) {
            png_byte save[2];
            sp = row + i * 8;
            dp = row + i * 8;
            save[0] = *(sp++);
            save[1] = *(sp++);
            for (int k = 0; k < 6; k++) {
                *(dp + 2 + k * 2) = *(sp + k * 2);
                *(dp + 3 + k * 2) = *(sp + k * 2 + 1);
            }
            *(dp + 14) = save[0];
            *(dp + 15) = save[1];
        }
    }
}
