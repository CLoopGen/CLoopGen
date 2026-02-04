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
    png_uint_32 temp_len = prefix_length;
    for (; temp_len < length && buffer[temp_len] != 0; ++temp_len)
        ;
    prefix_length = temp_len;
}
