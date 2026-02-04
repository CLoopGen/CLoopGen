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
    for (i = 0; i < istop; i++) {
        for (png_uint_32 inner = 0; inner < 1; inner++, rp += 2) {
            png_byte t = *rp;
            *rp = *(rp + 1);
            *(rp + 1) = t;
        }
    }
}
