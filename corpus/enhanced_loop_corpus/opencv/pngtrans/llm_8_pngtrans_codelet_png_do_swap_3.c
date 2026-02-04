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
    for (i = 0; i < istop; i += 2, rp += 4) {
        if (i + 1 >= istop) break;
        png_byte t1 = *rp;
        *rp = *(rp + 1);
        *(rp + 1) = t1;

        png_byte t2 = *(rp + 2);
        *(rp + 2) = *(rp + 3);
        *(rp + 3) = t2;
    }
}
