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
    // Variant 1: Strided memory access (stride of 2)
    png_uint_32 i;
    for (prefix_length = 0; prefix_length < length; prefix_length += 2) {
        if (buffer[prefix_length] == 0) break;
        // Handle odd index overflow safely
        if (prefix_length + 1 < length && buffer[prefix_length + 1] != 0) {
            prefix_length++; // Continue counting if next is non-zero
        } else {
            break;
        }
    }
    // Final adjustment: scan forward from last checked point to ensure correctness
    for (i = prefix_length; i < length && buffer[i] != 0; ++i) {
        prefix_length = i + 1;
    }
}
