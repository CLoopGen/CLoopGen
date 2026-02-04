#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;
extern png_uint_32 row_width;
extern unsigned int gray_high;
extern unsigned int gray_low;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_uint_32 step = 2;
    for (i = 0; i < row_width; i += step) {
        if (i + 1 < row_width) {
            png_byte s_prev1 = *(sp - 1) & 255U;
            png_byte s_curr1 = *(sp) & 255U;
            png_byte s_prev2 = *(sp - 3) & 255U;
            png_byte s_curr2 = *(sp - 2) & 255U;

            int cond1 = (s_prev1 == gray_high && s_curr1 == gray_low);
            int cond2 = (s_prev2 == gray_high && s_curr2 == gray_low);

            *dp-- = cond1 ? 0 : 255;
            *dp-- = cond1 ? 0 : 255;
            *dp-- = cond2 ? 0 : 255;
            *dp-- = cond2 ? 0 : 255;

            *dp-- = *sp--;
            *dp-- = *sp--;
            *dp-- = *sp--;
            *dp-- = *sp--;
        } else {
            if ((*(sp - 1) & 255U) == gray_high && (*(sp) & 255U) == gray_low) {
                *dp-- = 0;
                *dp-- = 0;
            } else {
                *dp-- = 255;
                *dp-- = 255;
            }
            *dp-- = *sp--;
            *dp-- = *sp--;
        }
    }
}
