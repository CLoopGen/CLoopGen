#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_uint_32 row_width;
extern png_bytep sp;
extern png_bytep dp;
extern png_byte save[2];
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_byte temp;
    for (i = 0; i < row_width; i++) {
        temp = sp[-1];
        save[0] = sp[-2];
        save[1] = sp[-3];
        sp -= 3;
        dp[-6] = sp[-4];
        dp[-5] = sp[-3];
        dp[-4] = sp[-2];
        dp[-3] = sp[-1];
        dp[-2] = temp;
        dp[-1] = save[0];
        *(--dp) = save[1];
        sp -= 4;
        dp -= 7;
    }
}
