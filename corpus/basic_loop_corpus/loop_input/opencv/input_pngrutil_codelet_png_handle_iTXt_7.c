#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int png_uint_32;
typedef unsigned char png_byte;
typedef png_byte *png_bytep;

png_uint_32 length = 16777216; // ~16.78 million bytes (~16MB)
png_bytep buffer;
png_uint_32 prefix_length;

void init_vars() {
    buffer = (png_bytep)malloc(length);
    if (!buffer) {
        exit(1);
    }
    // Fill buffer with non-zero up to a point near the end to ensure loop runs long enough
    for (png_uint_32 i = 0; i < length - 1; ++i) {
        buffer[i] = 1;
    }
    buffer[length - 1] = 0; // null terminator to break the loop
    prefix_length = 0;
}