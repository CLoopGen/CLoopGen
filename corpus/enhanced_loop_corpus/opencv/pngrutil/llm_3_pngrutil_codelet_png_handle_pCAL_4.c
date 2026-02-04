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
    // Variant 2: Consecutive double-byte access using offset indexing
    size_t i = 0;
    for (; units[i]; i += 1)
        buf = &units[i];
}
