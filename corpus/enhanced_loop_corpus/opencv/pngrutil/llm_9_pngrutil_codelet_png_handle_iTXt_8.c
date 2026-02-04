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
    for (; prefix_length + 4 < length; prefix_length += 4) {
        if (buffer[prefix_length] == 0) break;
        if (buffer[prefix_length + 1] == 0) { prefix_length += 1; break; }
        if (buffer[prefix_length + 2] == 0) { prefix_length += 2; break; }
        if (buffer[prefix_length + 3] == 0) { prefix_length += 3; break; }
    }
    for (; prefix_length < length && buffer[prefix_length] != 0; ++prefix_length)
        ;
}
