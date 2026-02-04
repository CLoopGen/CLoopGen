#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep row;
extern int bytes_per_pixel;
extern png_uint_32 row_width;
extern png_bytep rp;
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < row_width; i += 2) {
        png_bytep rp1 = row + i * bytes_per_pixel;
        png_uint_32 s0_1 = (png_uint_32)(*(rp1) << 8) | *(rp1 + 1);
        png_uint_32 s1_1 = (png_uint_32)(*(rp1 + 2) << 8) | *(rp1 + 3);
        png_uint_32 s2_1 = (png_uint_32)(*(rp1 + 4) << 8) | *(rp1 + 5);
        png_uint_32 red1 = (png_uint_32)((s0_1 - s1_1) & 65535L);
        png_uint_32 blue1 = (png_uint_32)((s2_1 - s1_1) & 65535L);

        *(rp1) = (png_byte)(red1 >> 8);
        *(rp1 + 1) = (png_byte)red1;
        *(rp1 + 4) = (png_byte)(blue1 >> 8);
        *(rp1 + 5) = (png_byte)blue1;

        if (i + 1 < row_width) {
            png_bytep rp2 = row + (i + 1) * bytes_per_pixel;
            png_uint_32 s0_2 = (png_uint_32)(*(rp2) << 8) | *(rp2 + 1);
            png_uint_32 s1_2 = (png_uint_32)(*(rp2 + 2) << 8) | *(rp2 + 3);
            png_uint_32 s2_2 = (png_uint_32)(*(rp2 + 4) << 8) | *(rp2 + 5);
            png_uint_32 red2 = (png_uint_32)((s0_2 - s1_2) & 65535L);
            png_uint_32 blue2 = (png_uint_32)((s2_2 - s1_2) & 655335L);

            *(rp2) = (png_byte)(red2 >> 8);
            *(rp2 + 1) = (png_byte)red2;
            *(rp2 + 4) = (png_byte)(blue2 >> 8);
            *(rp2 + 5) = (png_byte)blue2;
        }
    }
}
