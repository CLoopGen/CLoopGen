#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_uint_32 length;
extern png_bytep buffer;
extern png_uint_32 prefix_length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    prefix_length = 0;
    png_uint_32 step = 4;
    png_uint_32 aligned_length = length - (length % step);

    for (png_uint_32 i = 0; i < aligned_length; i += step) {
        if (buffer[i] != 0) { prefix_length++; } else { break; }
        if (buffer[i+1] != 0) { prefix_length++; } else { break; }
        if (buffer[i+2] != 0) { prefix_length++; } else { break; }
        if (buffer[i+3] != 0) { prefix_length++; } else { break; }
    }

    for (; prefix_length < length && buffer[prefix_length] != 0; ++prefix_length)
        ;
}
