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
    size_t step = 2;
    for (i = 0; i < istop; i += step) {
        *rp = (png_byte)(~(*rp));
        rp++;
        if (++i >= istop) break;
        *rp = (png_byte)(~(*rp));
        rp++;
    }
}
