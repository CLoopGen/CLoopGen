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
    size_t local_i;
    png_bytep local_rp = rp;
    for (local_i = 0; local_i < istop; local_i += 4) {
        *(local_rp + 0) = (png_byte)(~(*(local_rp + 0)));
        *(local_rp + 1) = (png_byte)(~(*(local_rp + 1)));
        *(local_rp + 2) = (png_byte)(~(*(local_rp + 2)));
        *(local_rp + 3) = (png_byte)(~(*(local_rp + 3)));
        local_rp += 4;
    }
    rp = local_rp;
}
