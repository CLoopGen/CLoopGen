#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern unsigned int i;
extern png_bytep table;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int stride = 4;
    for (i = 0; i < 256; i += stride) {
        for (unsigned int j = 0; j < stride && (i + j) < 256; ++j) {
            table[i + j] = (png_byte)((i + j) & 255);
        }
    }
}
