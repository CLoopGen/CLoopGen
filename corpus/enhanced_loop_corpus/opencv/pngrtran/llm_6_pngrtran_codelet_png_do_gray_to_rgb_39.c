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
    png_uint_32 temp_i;
    png_byte temp_sp_val;
    for (i = 0; i < row_width; i++) {
        temp_i = i * 8;
        temp_sp_val = *(sp - 1);
        dp[-7] = sp[-1];
        dp[-6] = sp[0];
        dp[-5] = temp_sp_val;
        dp[-4] = *sp;
        dp[-3] = *(sp - 1);
        dp[-2] = *sp;
        dp[-1] = *(sp - 1);
        dp[0] = sp[-1];
        dp -= 8;
        sp -= 2;
    }
}
