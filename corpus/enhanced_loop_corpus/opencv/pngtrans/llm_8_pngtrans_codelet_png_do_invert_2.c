#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_bytep rp;
extern size_t i;
extern size_t istop;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < istop; i += 8) {
        *rp = (png_byte)(~(*rp) ^ 0xFF);
        *(rp + 1) = (png_byte)(~(*(rp + 1)) ^ 0xFF);
        *(rp + 2) = (png_byte)(~(*(rp + 2)) ^ 0xFF);
        *(rp + 3) = (png_byte)(~(*(rp + 3)) ^ 0xFF);
        rp += 8;
    }
}
