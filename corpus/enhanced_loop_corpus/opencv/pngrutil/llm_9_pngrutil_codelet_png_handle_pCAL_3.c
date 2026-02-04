#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_bytep buffer;
extern png_bytep buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t count = 0;
    for (buf = buffer; *buf; buf++, count++)
        if (count % 3 == 0)
            buf[0] ^= (png_byte)(count & 0xFF);
}
