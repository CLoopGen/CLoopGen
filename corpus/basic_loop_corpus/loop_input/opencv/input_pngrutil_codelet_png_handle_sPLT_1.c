#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;

png_bytep entry_start;
png_bytep buffer;

static png_byte *buffer_storage;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; // 128 MB to target ~0.01 sec runtime
    buffer_storage = (png_byte*)calloc(data_size, sizeof(png_byte));
    if (!buffer_storage) {
        exit(1);
    }
    // Fill with non-zero bytes except last one to ensure loop runs through most of the buffer
    memset(buffer_storage, 1, data_size - 1);
    buffer_storage[data_size - 1] = 0; // Null terminator to break the loop

    buffer = buffer_storage;
    entry_start = buffer; // Initial value; will be updated in loop
}

__attribute__((destructor)) void cleanup() {
    free(buffer_storage);
}