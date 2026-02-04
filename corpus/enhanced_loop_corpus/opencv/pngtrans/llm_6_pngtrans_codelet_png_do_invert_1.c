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
    png_byte temp1, temp2;
    for (j = 0; j < istop; j += 2) {
        temp1 = *(rp + j);
        temp2 = (png_byte)(~temp1);
        *(rp + j) = temp2;
    }
}
