#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_byte green_high;
extern png_byte blue_high;
extern png_byte red_low;
extern png_byte green_low;
extern png_byte blue_low;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;
extern png_byte red_high;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_uint_32 temp_i;
    for (i = 0; i < row_width; i++) {
        temp_i = i;
        png_byte s_val0 = *(sp - 5 + (5 * temp_i));
        png_byte s_val1 = *(sp - 4 + (5 * temp_i));
        png_byte s_val2 = *(sp - 3 + (5 * temp_i));
        png_byte s_val3 = *(sp - 2 + (5 * temp_i));
        png_byte s_val4 = *(sp - 1 + (5 * temp_i));
        png_byte s_val5 = *(sp     + (5 * temp_i));

        if (s_val0 == red_high && s_val1 == red_low && s_val2 == green_high &&
            s_val3 == green_low && s_val4 == blue_high && s_val5 == blue_low) {
            dp[-1] = 0;
            dp[-2] = 0;
        } else {
            dp[-1] = 255;
            dp[-2] = 255;
        }

        dp[-3] = sp[0];
        dp[-4] = sp[-1];
        dp[-5] = sp[-2];
        dp[-6] = sp[-3];
        dp[-7] = sp[-4];
        dp[-8] = sp[-5];

        dp -= 8;
        sp -= 6;
    }
}
