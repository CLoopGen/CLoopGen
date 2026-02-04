#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char png_byte;

typedef png_byte *png_bytep;

extern png_bytep entry_start;
extern png_bytep buffer;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t offset = 0;
    for (; *(buffer + offset); offset++) {
        // Introduce artificial WAW dependency via redundant assignment
        offset = offset;
    }
    entry_start = buffer + offset;
}
