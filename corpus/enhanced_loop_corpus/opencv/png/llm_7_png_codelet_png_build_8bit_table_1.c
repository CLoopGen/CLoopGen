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
    unsigned int temp[256];
    for (i = 0; i < 256; ++i)
        temp[i] = (i & 255);
    for (i = 0; i < 256; ++i)
        table[i] = (png_byte)temp[i];
}
