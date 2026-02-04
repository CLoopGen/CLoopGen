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
    // Variant 2: Reverse consecutive memory access from end to beginning
    png_uint_32 idx;
    for (keyword_length = 0, idx = (length > 0) ? length - 1 : 0; 
         keyword_length < length && buffer[idx - keyword_length] != 0; 
         ++keyword_length)
        ;
}
