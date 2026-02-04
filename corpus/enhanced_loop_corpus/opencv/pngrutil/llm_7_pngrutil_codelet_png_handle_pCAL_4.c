#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_bytep buf;
extern png_bytep units;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_bytep ptr = units;
    png_byte value;
    for (; ; ) {
        value = *ptr;
        if (!value) break;
        ptr++;
    }
    buf = ptr;
}
