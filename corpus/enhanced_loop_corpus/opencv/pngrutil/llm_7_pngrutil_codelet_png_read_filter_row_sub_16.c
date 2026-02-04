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
    size_t k;
    png_bytep write_ptr = rp + bpp;
    png_bytep read_ptr = rp;
    for (k = bpp; k < istop; k++) {
        *(write_ptr - bpp) = (png_byte)(((int)(*(write_ptr - bpp)) + (int)(*(read_ptr - bpp))) & 255);
        write_ptr++;
        read_ptr++;
    }
}
