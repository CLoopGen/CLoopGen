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
    if (length == 0) {
        return;
    }
    for (; prefix_length < length; ++prefix_length) {
        if (buffer[prefix_length] == 0) {
            break;
        }
    }
}
