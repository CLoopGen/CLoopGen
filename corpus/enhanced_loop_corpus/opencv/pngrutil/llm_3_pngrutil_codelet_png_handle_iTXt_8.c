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
    // Variant 2: Consecutive dual-element prefetch pattern with unrolled access
    png_uint_32 i = prefix_length;
    for (; i + 1 < length; i += 2) {
        if (buffer[i] == 0) {
            prefix_length = i;
            return;
        }
        if (buffer[i + 1] == 0) {
            prefix_length = i + 1;
            return;
        }
    }
    // Handle remaining element
    for (; i < length && buffer[i] != 0; ++i)
        ;
    prefix_length = i;
}
