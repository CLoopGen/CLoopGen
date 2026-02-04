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



void loop() {
    // Variant 1: Strided memory access (access every 2nd element)
    png_uint_32 i = prefix_length;
    for (; i < length && (i >= length || buffer[i] != 0); i += 2) {
        if (i + 1 < length && buffer[i + 1] == 0) {
            prefix_length = i + 1;
            return;
        }
        prefix_length = i;
    }
    if (i == prefix_length || i >= length) {
        for (; prefix_length < length && buffer[prefix_length] != 0; ++prefix_length);
    }
}
