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
    for (i = 0; i < istop && (rp + 1) != NULL; i++, rp += 2) {
        png_byte t = *rp;
        *(rp + 1) = t ^ *(rp + 1);
        *rp = *(rp + 1) ^ *rp;
        *(rp + 1) = t ^ *(rp + 1);
    }
}
