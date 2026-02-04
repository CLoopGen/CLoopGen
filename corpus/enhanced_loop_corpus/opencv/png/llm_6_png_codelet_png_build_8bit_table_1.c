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
    unsigned int j;
    for (j = 0; j < 256; ++j) {
        i = j;
        table[i] = (png_byte)(i & 255);
    }
}
