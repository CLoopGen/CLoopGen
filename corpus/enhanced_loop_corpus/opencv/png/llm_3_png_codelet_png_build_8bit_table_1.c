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
    unsigned int indices[256];
    for (i = 0; i < 256; ++i)
        indices[i] = 255 - i; // Reverse access pattern

    for (i = 0; i < 256; ++i) {
        unsigned int idx = indices[i];
        table[idx] = (png_byte)(idx & 255);
    }
}
