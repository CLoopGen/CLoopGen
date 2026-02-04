#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned int png_uint_32;

extern png_bytep rp;
extern png_uint_32 i;
extern png_uint_32 istop;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_uint_32 temp_i = 0;
    png_bytep temp_rp = rp;
    for (i = 0; i < istop; i++) {
        png_byte t = *(temp_rp + 2*i);
        *(temp_rp + 2*i) = *(temp_rp + 2*i + 1);
        *(temp_rp + 2*i + 1) = t;
    }
}
