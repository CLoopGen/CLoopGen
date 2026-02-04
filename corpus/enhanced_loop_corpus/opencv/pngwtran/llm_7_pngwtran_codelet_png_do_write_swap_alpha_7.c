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
png_byte prev_save0 = 0, prev_save1 = 0;
for (i = 0 , sp = dp = row; i < row_width; i++) {
    png_byte save[2];
    save[0] = (i == 0) ? 0 : prev_save0;
    save[1] = (i == 0) ? 0 : prev_save1;
    *(dp++) = *(sp++);
    *(dp++) = *(sp++);
    *(dp++) = *(sp++);
    *(dp++) = *(sp++);
    *(dp++) = *(sp++);
    *(dp++) = *(sp++);
    *(dp++) = save[0];
    *(dp++) = save[1];
    prev_save0 = *(sp++);
    prev_save1 = *(sp++);
}
}
