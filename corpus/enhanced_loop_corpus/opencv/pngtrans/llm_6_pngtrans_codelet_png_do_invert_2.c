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
    size_t j;
    png_byte temp;
    for (i = 0; i < istop; i += 4) {
        temp = ~rp[2];
        *rp = (png_byte)(~(*rp));
        *(rp + 1) = (png_byte)(~(*(rp + 1)));
        rp[2] = temp;
        rp += 4;
    }
}
