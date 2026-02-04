#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_uint_32 length;
extern png_bytep buffer;
extern png_uint_32 keyword_length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    png_uint_32 i;
    for (i = 0; i < length; ++i) {
        keyword_length = i;
        if (buffer[i] == 0) {
            break;
        }
    }
    if (buffer[keyword_length] != 0) {
        keyword_length = length;
    }
}
