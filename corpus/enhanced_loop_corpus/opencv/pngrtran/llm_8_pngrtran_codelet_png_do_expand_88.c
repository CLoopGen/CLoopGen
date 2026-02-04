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
    for (i = 0; i < row_width; i += 2) {
        if (i + 1 < row_width) {
            png_byte sp_val0_5 = *(sp - 5), sp_val0_4 = *(sp - 4), sp_val0_3 = *(sp - 3);
            png_byte sp_val0_2 = *(sp - 2), sp_val0_1 = *(sp - 1), sp_val0_0 = *(sp);
            png_byte sp_val1_5 = *(sp - 11), sp_val1_4 = *(sp - 10), sp_val1_3 = *(sp - 9);
            png_byte sp_val1_2 = *(sp - 8), sp_val1_1 = *(sp - 7), sp_val1_0 = *(sp - 6);

            int match0 = (sp_val0_5 == red_high && sp_val0_4 == red_low && 
                          sp_val0_3 == green_high && sp_val0_2 == green_low && 
                          sp_val0_1 == blue_high && sp_val0_0 == blue_low);
            int match1 = (sp_val1_5 == red_high && sp_val1_4 == red_low && 
                          sp_val1_3 == green_high && sp_val1_2 == green_low && 
                          sp_val1_1 == blue_high && sp_val1_0 == blue_low);

            *dp-- = match0 ? 0 : 255;
            *dp-- = match0 ? 0 : 255;
            *dp-- = match1 ? 0 : 255;
            *dp-- = match1 ? 0 : 255;

            *dp-- = *sp--;
            *dp-- = *sp--;
            *dp-- = *sp--;
            *dp-- = *sp--;
            *dp-- = *sp--;
            *dp-- = *sp--;

            *dp-- = *sp--;
            *dp-- = *sp--;
            *dp-- = *sp--;
            *dp-- = *sp--;
            *dp-- = *sp--;
            *dp-- = *sp--;
        } else {
            if (*(sp - 5) == red_high && *(sp - 4) == red_low && *(sp - 3) == green_high && 
                *(sp - 2) == green_low && *(sp - 1) == blue_high && *(sp) == blue_low) {
                *dp-- = 0;
                *dp-- = 0;
            } else {
                *dp-- = 255;
                *dp-- = 255;
            }
            *dp-- = *sp--;
            *dp-- = *sp--;
            *dp-- = *sp--;
            *dp-- = *sp--;
            *dp-- = *sp--;
            *dp-- = *sp--;
        }
    }
}
