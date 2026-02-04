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
    png_byte temp[2];
    for (i = 0; i < row_width; i++) {
        temp[0] = sp[-1];
        temp[1] = sp[-2];
        sp -= 2;
        dp[-3] = sp[-1];
        dp[-2] = sp[-2];
        dp[-1] = temp[0];
        dp[0]  = temp[1];
        sp -= 2;
        dp -= 4;
    }
}
