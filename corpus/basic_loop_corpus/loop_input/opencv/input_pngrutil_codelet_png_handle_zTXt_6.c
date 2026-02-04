#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int png_uint_32;
typedef unsigned char png_byte;
typedef png_byte *png_bytep;

png_uint_32 length;
png_bytep buffer;
png_uint_32 keyword_length;

void init_vars() {
    // Allocate approximately 64MB of data to target ~0.01s execution time
    size_t data_size = 67108864; // 64 * 1024 * 1024 bytes
    length = data_size;

    buffer = (png_bytep)malloc(length);
    if (!buffer) {
        exit(1);
    }

    // Initialize buffer with non-zero values except at the end
    memset(buffer, 1, length - 1);
    buffer[length - 1] = 0; // Null terminator to stop the loop

    keyword_length = 0;
}