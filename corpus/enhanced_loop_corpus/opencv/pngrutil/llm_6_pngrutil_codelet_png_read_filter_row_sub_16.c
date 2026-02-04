#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern size_t i;
extern size_t istop;
extern unsigned int bpp;
extern png_bytep rp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    png_bytep current = rp;
    for (j = bpp; j < istop; j++) {
        png_byte temp = *(current - bpp);
        *current = (png_byte)(((int)(*current) + (int)temp) & 255);
        current++;
    }
}
